#ifndef NetManager_h
#define NetManager_h

#include "Main.h"

class NetManager
{
public:

    NetManager();
    bool activate();
    bool disconnectPlayer();
    bool isConnected();

private:

    bool connected;
    TCPConnection tcpConnection;
};

#endif /* NetManager_h */




