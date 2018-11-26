#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include "Main.h"

class TCPConnection {
public:
    TCPConnection();
    ~TCPConnection();
    
    bool connectToServer(Player& player, std::string host, Uint16 port);
    bool disconnectFromServer(Player& player);

    bool isConnectionGood();

    void queuePacket(BasePacket* packet);

    void startSenderThread();

    std::unique_ptr<BasePacket> getNextPacket();

    void sendPacket();

    
private:
    IPaddress ipAddress;
    TCPsocket socket;
    SDLNet_SocketSet socketSet;
    UniversalPacket uniPacket;
    std::thread* senderThread;
    std::atomic_bool closeThread;
    std::atomic_bool connectionGood;
    std::mutex queueMtx;
    std::queue<std::unique_ptr<BasePacket>> packetQueue;

    void sendPackets();

};




#endif
