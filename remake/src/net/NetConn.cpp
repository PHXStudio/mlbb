#include "NetConn.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <cstring>

namespace godot {

NetConn::NetConn() {
  status = STATUS_NONE;
  socket.instantiate();
  proxy_ = nullptr;
}

NetConn::~NetConn() {
  disconnect_from_host();
}

void NetConn::_bind_methods() {
  // 注册方法
  ClassDB::bind_method(D_METHOD("connect_to_host", "host", "port"),
                       &NetConn::connect_to_host);
  ClassDB::bind_method(D_METHOD("disconnect_from_host"),
                       &NetConn::disconnect_from_host);
  //ClassDB::bind_method(D_METHOD("get_status"), &ServerAgent::get_status_int);

  // 注册基本连接信号
  ADD_SIGNAL(MethodInfo("connected"));
  ADD_SIGNAL(MethodInfo("disconnected"));
  ADD_SIGNAL(MethodInfo("connection_error"));

}

void NetConn::connect_to_host(const String &p_host, int p_port) {
  UtilityFunctions::print("[NetConn] Attempting to connect to host: ", p_host, ":", p_port);
  disconnect_from_host();
  Error err = socket->connect_to_host(p_host, p_port);
  if (err != OK) {
    UtilityFunctions::print("[NetConn] Connection failed, error code: ", err);
    status = STATUS_ERROR;
    if (!proxy_) {

       emit_signal("connection_error");
    }
    return;
  }
  socket->set_no_delay(true);
  status = STATUS_CONNECTING;
  recv_temp_buffer.clear();
  UtilityFunctions::print("[NetConn] Connection initiated, status: STATUS_CONNECTING");
}

void NetConn::disconnect_from_host() {
  if (socket.is_valid()) {
    socket->disconnect_from_host();
  }
  status = STATUS_DISCONNECTED;
}

void NetConn::update_connection() {
  if (status == STATUS_NONE || status == STATUS_DISCONNECTED)
    return;

  socket->poll();
  StreamPeerTCP::Status s = socket->get_status();

  if (status == STATUS_CONNECTING) {
    if (s == StreamPeerTCP::STATUS_CONNECTED) {
      UtilityFunctions::print("[NetConn] Connected to server");
      status = STATUS_CONNECTED;
    } else if (s == StreamPeerTCP::STATUS_ERROR ||
               s == StreamPeerTCP::STATUS_NONE) {
      UtilityFunctions::print("[NetConn] Connection error, status: ", s);
      status = STATUS_ERROR;
      return;
    }
  }

  if (status == STATUS_CONNECTED) {
    if (s != StreamPeerTCP::STATUS_CONNECTED) {
      UtilityFunctions::print("[NetConn] Disconnected, socket status: ", s);
      status = STATUS_DISCONNECTED;
      return;
    }

    // 读取数据
    int bytes_available = socket->get_available_bytes();
    if (bytes_available > 0) {
      UtilityFunctions::print("[NetConn] Received ", bytes_available, " bytes from socket");
      PackedByteArray data =
          socket->get_data(bytes_available)[1]; // [0] is error, [1] is data
      recv_temp_buffer.append_array(data);

      // 处理接收到的数据
      on_data_received(recv_temp_buffer);
    }
  }
}

void NetConn::check_connection()
{
      // 根据连接状态发送信号
    NetConn::Status status = get_status();
    static NetConn::Status last_status = NetConn::STATUS_NONE;
    if (status != last_status) {
      switch (status) {
        case NetConn::STATUS_CONNECTED:
          emit_signal("connected");
          break;
        case NetConn::STATUS_DISCONNECTED:
          emit_signal("disconnected");
          break;
        case NetConn::STATUS_ERROR:
          emit_signal("connection_error");
          break;
        default:
          break;
      }
      last_status = status;
    }
}

void NetConn::on_data_received(const PackedByteArray &data) {
  // 处理接收到的数据
  int processed = handleReceived(data);
  UtilityFunctions::print("[NetConn] Processed ", processed, " bytes from buffer");
  if (processed > 0) {
    recv_temp_buffer = recv_temp_buffer.slice(processed);
  } else if (processed < 0) {
    // 协议解析错误
    UtilityFunctions::print("[NetConn] Protocol parse error, disconnecting");
    disconnect_from_host();
  }
}

void NetConn::write(const void *data, size_t len) {
  const uint8_t *ptr = static_cast<const uint8_t *>(data);
  for (size_t i = 0; i < len; ++i) {
    send_buffer.append(ptr[i]);
  }
}

void NetConn::initSendingData()
{
  UtilityFunctions::print("[NetConn] initSendingData: Clearing and initializing send buffer");
  send_buffer.clear();
  uint16_t tempHdr = 0;
  write(&tempHdr, sizeof(tempHdr));
  UtilityFunctions::print("[NetConn] initSendingData: Buffer size after header: ", send_buffer.size(), " bytes");
}

void NetConn::flushSendingData()
{
  UtilityFunctions::print("[NetConn] flushSendingData: Current buffer size: ", send_buffer.size(), " bytes");
  uint16_t dLen = send_buffer.size() - sizeof(uint16_t);
  uint8_t *ptr = send_buffer.ptrw();
  memcpy(ptr, &dLen, sizeof(uint16_t));
  UtilityFunctions::print("[NetConn] flushSendingData: Data length written to header: ", dLen);
  if (get_status() == NetConn::STATUS_CONNECTED) {
    Ref<StreamPeerTCP> sock = get_socket();
    if (sock.is_valid()) {
      sock->put_data(send_buffer);
      UtilityFunctions::print("[ServerAgent] Data sent to socket: ", send_buffer.size(), " bytes");
    }
  } else {
    UtilityFunctions::print("[NetConn] flushSendingData: Not connected, status: ", get_status());
  }
  send_buffer.clear();
}

int NetConn::handleReceived(const PackedByteArray &data) {
  if (proxy_ == nullptr)
    return 0;

  int processed = 0;
  const uint8_t *d = data.ptr();
  size_t size = (size_t)data.size();
  size_t dLeft = size;

  while (true) {
    if (sizeof(uint16_t) > dLeft)
      return processed;
    uint16_t dLen = *((uint16_t *)d);

    size_t dTLen = sizeof(uint16_t) + dLen;
    if (dTLen > dLeft)
      return processed;

    // 使用 PackedByteArray 的切片构造 Reader
    PackedByteArray slice =
        data.slice(processed + sizeof(uint16_t), processed + dTLen);
    ProtocolBufferReader r(slice);
    // Server2Client_Dispatcher 会调用 proxy_ 的虚函数
    if(!proxy_->dispatch(&r))
    {
      return -1;
    }

    d += dTLen;
    dLeft -= dTLen;
    processed += dTLen;
  }
  return processed;
}

} // namespace godot
