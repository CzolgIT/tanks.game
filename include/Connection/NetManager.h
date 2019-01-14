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

    bool canPollPacket();
    BasePacket* pollPacket();

    NetPlayer* netPlayer;
    void clear();
    int getMyId();
    std::string getMyNickname();
    std::map<int, std::string> clientsMap;
    void getAllPlayersData();

private:

    bool syncTimeWithServer(NetPlayer* player, Uint32& globalTime);
    std::queue<BasePacket*> packetQueue;

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




