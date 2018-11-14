#ifndef NetManager_h
#define NetManager_h

#include "Main.h"

class NetManager
{
public:

    NetManager();
    void activate();

private:

    TCPConnection tcpConnection;
};

#endif /* NetManager_h */




