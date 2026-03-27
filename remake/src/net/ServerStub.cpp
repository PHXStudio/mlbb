#include "ServerStub.h"


namespace godot 
{
    ProtocolWriter* ServerStub::methodBegin(){
        conn->initSendingData();
        return conn.ptr();
    }

    void ServerStub::methodEnd() {
        conn->flushSendingData();
    }
}