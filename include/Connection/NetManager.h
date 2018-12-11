#ifndef NetManager_h
#define NetManager_h

#include "Main.h"

class NetManager
{
public:

    NetManager();
    ~NetManager();
    bool activate();
    bool connect(std::string host, Uint16 port, Uint32& globalTime);
    bool disconnectPlayer();
    bool isConnected();

    void read();

    void tcpSend(BasePacket* packet);
    void udpSend(BasePacket* packet);

    bool pollPacket(std::unique_ptr<BasePacket>&packet);

    NetPlayer* netPlayer;

private:

    bool syncTimeWithServer(const NetPlayer& player, Uint32& globalTime);

    std::queue<std::unique_ptr<BasePacket>> packetQueue;

    std::atomic_bool closeSenderThread; //closes thread when true
    std::thread* senderThread;

    bool connected;
    TCPConnection tcpConnection;
    UDPConnection udpConnection;

    void startSenderThread();

    void sendPackets();
};

#endif /* NetManager_h */




