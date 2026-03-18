#ifndef __GODOT_NET_CONN_H__
#define __GODOT_NET_CONN_H__

#include <godot_cpp/classes/stream_peer_tcp.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/string.hpp>

#include "../rpc/ProtocolBufferReader.h"
#include "../rpc/ProtocolWriter.h"
#include "../rpc_gen/proto_godot.h"

namespace godot {

/**
 * 纯网络传输层类。
 * 负责管理 TCP Socket 连接、数据的收发和协议层面的消息分帧处理。
 * 不涉及任何游戏协议逻辑，只提供底层的网络传输能力。
 */
class NetConn 
  :public Resource, 
  public ProtocolWriter {
  friend class ServerAgent;

  GDCLASS(NetConn, Resource)
public:
  enum Status {
    STATUS_NONE,
    STATUS_CONNECTING,
    STATUS_CONNECTED,
    STATUS_DISCONNECTED,
    STATUS_ERROR
  };

  NetConn();
  virtual ~NetConn();

  static void _bind_methods();
  // --- 网络传输方法 ---

  /**
   * 连接到指定主机
   */
  void connect_to_host(const String &p_host, int p_port);

  /**
   * 断开连接
   */
  void disconnect_from_host();

  /**
   * 获取当前连接状态
   */
  Status get_status() const { return status; }
  int get_status_int() const { return (int)status; }

  inline void set_proxy(Server2Client_Proxy* proxy){
    proxy_ = proxy;
  }
  /**
   * 更新连接状态（轮询socket并读取数据）
   * 由 ServerAgent._process 调用
   */
  void update_connection();
  void check_connection();
  /**
   * 处理接收到的原始字节数组
   * 解析消息并分发到 Server2Client_Proxy
   */
  virtual int handleReceived(const PackedByteArray &data);

  // --- 纯虚方法，由 ServerAgent 实现 ---

  void initSendingData();
  void flushSendingData();
protected:
  Ref<StreamPeerTCP> socket;
  Status status;
  PackedByteArray recv_temp_buffer; // 用于处理粘包/半包的临时缓存
  PackedByteArray send_buffer;  // 用于 ProtocolWriter 的发送缓存
  Server2Client_Proxy* proxy_ = nullptr; // 指向 ServerAgent，用于分发消息

  /**
   * 内部方法：实际执行连接更新
   */
  void _do_update_connection();

  /**
   * 数据接收回调 - 虚函数供子类重写
   */
  virtual void on_data_received(const PackedByteArray &data);



  // --- ProtocolWriter 实现 ---
  void write(const void *data, size_t len) override;

public:
  // 暴露socket给ServerAgent用于发送数据
  Ref<StreamPeerTCP> get_socket() const { return socket; }
};

} // namespace godot

#endif // __GODOT_NET_CONN_H__
