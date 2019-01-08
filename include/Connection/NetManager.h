#ifndef NetManager_h
#define NetManager_h

#include "Main.h"

class NetManager
{
public:

    NetManager();
    ~NetManager();
    bool connect(std::string host, Uint16 port, Uint32& globalTime);
    bool disconnectPlayer();
    bool isConnected();
    Uint32 getGlobalTime();
    void read();

    void tcpSend(BasePacket* packet);
    void udpSend(BasePacket* packet);
    void setGlobalTime(Uint32 newGlobalTime);
    bool pollPacket(std::unique_ptr<BasePacket>&packet);

    NetPlayer* netPlayer;

private:

    bool syncTimeWithServer(NetPlayer* player, Uint32& globalTime);

    std::queue<std::unique_ptr<BasePacket>> packetQueue;

    std::atomic_bool closeSenderThread; //closes thread when true
    std::thread* senderThread;

    bool connected;
    TCPConnection tcpConnection;
    UDPConnection udpConnection;
    Uint32 globalTime;
    void startSenderThread();

    void sendPackets();
};

#endif /* NetManager_h */




