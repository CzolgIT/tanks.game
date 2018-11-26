#ifndef NetManager_h
#define NetManager_h

#include "Main.h"

class NetManager
{
public:

    NetManager();
    bool activate();
    bool connect(Player& player, std::string host, Uint16 port, Uint32& globalTime);
    bool disconnectPlayer();
    bool isConnected();

    void tcpSend(BasePacket* packet);
    void udpSend(BasePacket* packet);

private:

    bool connected;
    TCPConnection tcpConnection;
    UDPConnection udpConnection;
};

#endif /* NetManager_h */




