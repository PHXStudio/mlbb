#ifndef __GODOT_SERVER_STUB_H__
#define __GODOT_SERVER_STUB_H__

#include <godot_cpp/variant/packed_byte_array.hpp>
#include "../rpc_gen/proto_godot.h"
#include "../rpc/ProtocolWriter.h"
#include "NetConn.h"
namespace godot
{
    class ServerStub
        : public Client2Server_Stub
    {
        GDCLASS(ServerStub, Client2Server_Stub)
        friend class ServerAgent;

    
        protected:

        static void _bind_methods() {
        }

        ProtocolWriter* methodBegin() override;
        void methodEnd() override;


        Ref<NetConn> conn;
        
    };

}

#endif