#ifndef __GODOT_SERVER_PROXY_H__
#define __GODOT_SERVER_PROXY_H__

#include <godot_cpp/variant/packed_byte_array.hpp>
#include "../rpc_gen/proto_godot.h"
#include "../rpc/ProtocolWriter.h"

namespace godot {

/**
 * 服务器端代理类。
 * 继承 Client2Server_Stub 用于发送消息到服务器。
 * 通过组合关系被 ServerAgent 使用。
 */
class ServerProxy 
    :public Server2Client_Proxy {
    GDCLASS(ServerProxy,Server2Client_Proxy)

    protected:
    static void _bind_methods() {
    }
};

} // namespace godot

#endif // __GODOT_SERVER_PROXY_H__
