//
// Created by inql on 26.11.18.
//

#ifndef TANKSGAME_UDPCONNECTION_H
#define TANKSGAME_UDPCONNECTION_H

#include "Main.h"

class UDPConnection {
public:
    UDPConnection();
    ~UDPConnection();

    //returns true if a connection was established, or false if failed to connectToServer
    bool connectToServer(std::string host, Uint16 port);

    //returns false if something went wrong
    bool isConnectionGood();

    //adds a packet to the queue
    void addPacketToQueue(BasePacket* packet);

    // Create a thread that sends packets as soon as they are added to the queue
    void startSenderThread();

    //pull the next packet from the server
    std::unique_ptr<BasePacket> getNextPacket();

    // send next packet from the queue
    void sendPacket();

private:
    IPaddress ipAddress;
    UDPsocket udpSocket;
    UniversalPacket universalPacket;
    std::atomic_bool connectionGood;

    std::atomic_bool closeThread;
    std::mutex queueMtx;
    std::queue<std::unique_ptr<BasePacket>> packetQueue;
    std::thread* senderThread;

    //sends queued packets, attached to the sender thread
    void sendPackets();
};


#endif //TANKSGAME_UDPCONNECTION_H
