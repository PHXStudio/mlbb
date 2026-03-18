#include "ServerAgent.h"
#include <godot_cpp/variant/utility_functions.hpp>

namespace godot {

ServerAgent::ServerAgent() {
  conn.instantiate();
  proxy.instantiate();
  stub.instantiate();
  stub->stub = this;
  conn->set_proxy(proxy.ptr());
}

ServerAgent::~ServerAgent() {
}

void ServerAgent::_bind_methods() {
  // 注册方法
  ClassDB::bind_method(D_METHOD("get_net_conn"),&ServerAgent::get_net_conn);
  ClassDB::bind_method(D_METHOD("get_server_proxy"), &ServerAgent::get_server_proxy);
  ClassDB::bind_method(D_METHOD("get_server_stub"), &ServerAgent::get_server_stub);
}


void ServerAgent::_notification(int p_what) {
  // 处理 Godot 内部通知
}

void ServerAgent::_process(double delta) {

  //UtilityFunctions::print("void ServerAgent::_process(double delta) {");

  conn->update_connection();
  conn->check_connection();
}

// --- ProtocolWriter 实现 ---

Ref<NetConn> ServerAgent::get_net_conn(){
  return conn;
}
Ref<ServerProxy> ServerAgent::get_server_proxy(){
  return proxy;
}
Ref<ServerStub> ServerAgent::get_server_stub(){
  return stub;
}
ProtocolWriter* ServerAgent::methodBegin(){
  conn->initSendingData();
  return conn.ptr();
}

void ServerAgent::methodEnd() {
  conn->flushSendingData();
}

////////




} // namespace godot
