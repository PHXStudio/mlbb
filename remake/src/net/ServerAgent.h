#ifndef __GODOT_SERVER_AGENT_H__
#define __GODOT_SERVER_AGENT_H__

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>

#include "../rpc_gen/proto_godot.h"
#include "../rpc/ProtocolWriter.h"
#include "NetConn.h"
#include "ServerProxy.h"
#include "ServerStub.h"
namespace godot {

/**
 * 服务器端代理类。
 * 继承 NetConn 网络传输层、Server2Client_Proxy 接收消息和 Client2Server_Stub 发送消息。
 * 负责管理协议操作、Godot 的 Node 系统和信号发射。
 */
class ServerAgent
    : public Node,
      public Client2Server_Stub {

  GDCLASS(ServerAgent, Node)

public:

  ServerAgent();
  ~ServerAgent();

  Ref<NetConn> get_net_conn();
  Ref<ServerProxy> get_server_proxy();
  Ref<ServerStub> get_server_stub();
  // --- NetConn 回调 ---
  void send_to_socket(const PackedByteArray &data);
  void on_data_received(const PackedByteArray &data);

  static void _bind_methods();
  void _process(double delta) override;

public: // 临时公开以注册虚拟函数
  void _notification(int p_what);


private:
  Ref<NetConn>    conn;
  Ref<ServerProxy> proxy;
  Ref<ServerStub> stub;
  godot::ProtocolWriter* methodBegin() override;
  void methodEnd() override;
};

} // namespace godot

#endif // __GODOT_SERVER_AGENT_H__
