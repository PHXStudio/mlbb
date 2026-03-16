#ifndef __GODOT_CONNECTION_H__
#define __GODOT_CONNECTION_H__

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/stream_peer_tcp.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>

#include "../rpc_gen/proto_godot.h"
#include "BINConnection.h"
#include "Server2ClientProxy.h"

namespace godot {

/**
 * 游戏主连接类，整合了底层的 BINConnection 模板和 Godot 的 Node 系统。
 * 负责管理 TCP Socket 连接，并将接收到的字节流分发给 RPC Proxy 处理。
 */
class Connection
    : public Node,
      public BINConnection<Client2Server_Stub, Server2ClientProxy> {

  GDCLASS(Connection, Node)

public:
  enum Status {
    STATUS_NONE,
    STATUS_CONNECTING,
    STATUS_CONNECTED,
    STATUS_DISCONNECTED,
    STATUS_ERROR
  };

  Connection();
  ~Connection();

  // --- Godot 接口 ---
  void connect_to_host(const String &p_host, int p_port);
  void disconnect_from_host();
  int get_status_int() const { return (int)status; }

  // --- BINConnection 实现 ---
  void on_data_ready(const PackedByteArray &p_data) override;

  // --- Client2Server_Stub 封装 (给 GDScript 调用发送消息) ---
  void send_login(Ref<COM_LoginInfo> info);
  void send_createPlayer(String playername, uint8_t playerTmpId);
  void send_enterGame(uint32_t playerInstId);
  void send_ping();

  static void _bind_methods();
  void _process(double delta) override;

public: // 临时公开以注册虚拟函数
  void _notification(int p_what);

protected:
private:
  Ref<StreamPeerTCP> socket;
  Ref<Server2ClientProxy> proxy;
  Status status;

  PackedByteArray recv_temp_buffer; // 用于处理粘包/半包的临时缓存

  void _update_connection();
};

} // namespace godot

#endif
