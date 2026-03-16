#include "Connection.h"
#include <godot_cpp/variant/utility_functions.hpp>

namespace godot {

Connection::Connection() {
  status = STATUS_NONE;
  socket.instantiate();
}

Connection::~Connection() { disconnect_from_host(); }

void Connection::_bind_methods() {
  // 注册方法
  ClassDB::bind_method(D_METHOD("connect_to_host", "host", "port"),
                       &Connection::connect_to_host);
  ClassDB::bind_method(D_METHOD("disconnect_from_host"),
                       &Connection::disconnect_from_host);
  ClassDB::bind_method(D_METHOD("get_status"), &Connection::get_status_int);

  // RPC 发送方法封装
  ClassDB::bind_method(D_METHOD("login", "info"), &Connection::send_login);
  ClassDB::bind_method(D_METHOD("create_player", "name", "tmp_id"),
                       &Connection::send_createPlayer);
  ClassDB::bind_method(D_METHOD("enter_game", "id"),
                       &Connection::send_enterGame);
  ClassDB::bind_method(D_METHOD("ping"), &Connection::send_ping);

  // 注册基本连接信号
  ADD_SIGNAL(MethodInfo("connected"));
  ADD_SIGNAL(MethodInfo("disconnected"));
  ADD_SIGNAL(MethodInfo("connection_error"));
}

void Connection::connect_to_host(const String &p_host, int p_port) {
  disconnect_from_host();
  Error err = socket->connect_to_host(p_host, p_port);
  if (err != OK) {
    status = STATUS_ERROR;
    emit_signal("connection_error");
    return;
  }
  status = STATUS_CONNECTING;
  recv_temp_buffer.clear();
}

void Connection::disconnect_from_host() {
  if (socket.is_valid()) {
    socket->disconnect_from_host();
  }
  status = STATUS_DISCONNECTED;
  emit_signal("disconnected");
}

void Connection::_notification(int p_what) {
  // 处理 Godot 内部通知
}

void Connection::_process(double delta) { _update_connection(); }

void Connection::_update_connection() {
  if (status == STATUS_NONE || status == STATUS_DISCONNECTED)
    return;

  socket->poll();
  StreamPeerTCP::Status s = socket->get_status();

  if (status == STATUS_CONNECTING) {
    if (s == StreamPeerTCP::STATUS_CONNECTED) {
      status = STATUS_CONNECTED;
      emit_signal("connected");
    } else if (s == StreamPeerTCP::STATUS_ERROR ||
               s == StreamPeerTCP::STATUS_NONE) {
      status = STATUS_ERROR;
      emit_signal("connection_error");
      return;
    }
  }

  if (status == STATUS_CONNECTED) {
    if (s != StreamPeerTCP::STATUS_CONNECTED) {
      status = STATUS_DISCONNECTED;
      emit_signal("disconnected");
      return;
    }

    // 读取数据
    int bytes_available = socket->get_available_bytes();
    if (bytes_available > 0) {
      PackedByteArray data =
          socket->get_data(bytes_available)[1]; // [0] is error, [1] is data
      recv_temp_buffer.append_array(data);

      // 让 BINConnection 处理数据，数据最终会流向 proxy
      int processed = handleReceived(recv_temp_buffer);
      if (processed > 0) {
        recv_temp_buffer = recv_temp_buffer.slice(processed);
      } else if (processed < 0) {
        // 协议解析错误
        disconnect_from_host();
      }
    }
  }
}

void Connection::on_data_ready(const PackedByteArray &p_data) {
  if (status == STATUS_CONNECTED && socket.is_valid()) {
    socket->put_data(p_data);
  }
}

// --- RPC Senders ---
void Connection::send_login(Ref<COM_LoginInfo> info) { login(info); }
void Connection::send_createPlayer(String playername, uint8_t playerTmpId) {
  createPlayer(playername, playerTmpId);
}
void Connection::send_enterGame(uint32_t playerInstId) {
  enterGame(playerInstId);
}
void Connection::send_ping() { ping(); }

} // namespace godot
