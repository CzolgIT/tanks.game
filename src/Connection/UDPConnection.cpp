//
// Created by inql on 26.11.18.
//
#include "Main.h"

UDPConnection::UDPConnection(): senderThread(nullptr) {
    closeThread = false;

    connectionGood = false;
}

UDPConnection::~UDPConnection() {

    //cleaning
    closeThread = true;
    if(senderThread)
        senderThread->join();


}

bool UDPConnection::connect(std::string host, Uint16 port) {
    //resolve server name

    if(SDLNet_ResolveHost(&ipAddress, host.c_str(),port)== -1){
        fprintf(stderr,"SDLNet_ResolveHost(%s %d): %s\n",host.c_str(), port, SDLNet_GetError());
        return false;
    }

    //open a socket on random port
    if( !(udpSocket=SDLNet_UDP_Open(0))){
        fprintf(stderr,"SDLNet_UDP_Open: %s\n",SDLNet_GetError());
        return false;
    }

    //if connected successfully, update flag
    connectionGood = true;
    return true;

}

bool UDPConnection::isConnectionGood() {
    return this->connectionGood;
}

void UDPConnection::addPacketToQueue(BasePacket *packet) {

    queueMtx.lock();

    packetQueue.push(std::unique_ptr<BasePacket>(packet));

    queueMtx.unlock();

}

void UDPConnection::startSenderThread() {

    //create a thread if one doesn't already exist
    if(senderThread == nullptr)
        senderThread = new std::thread(std::mem_fun(&UDPConnection::sendPackets),this);


}

std::unique_ptr<BasePacket> UDPConnection::getNextPacket() {
    UDPpacket packet;
    packet.data = universalPacket.getData();
    packet.maxlen = universalPacket.getSize();

    if(SDLNet_UDP_Recv(udpSocket,&packet))
    {
        return universalPacket.createFromContents();
    }else{
        return nullptr;
    }

}

void UDPConnection::sendPacket() {

    if( !packetQueue.empty()){

        // SDLNet packet creation
        UDPpacket packet;

        //destination

        packet.address.host = ipAddress.host;
        packet.address.port = ipAddress.port;

        queueMtx.lock();

        std::unique_ptr<BasePacket> qPacket = std::move(packetQueue.front());
        packetQueue.pop();

        queueMtx.unlock();

        packet.data = qPacket->getData();
        packet.len = qPacket->getSize();
        packet.maxlen = qPacket->getSize();

        if(SDLNet_UDP_Send(udpSocket,-1,&packet) <= 0){
            connectionGood = false;
        }


    }

}

void UDPConnection::sendPackets() {

    UDPpacket packet;

    packet.address.host = ipAddress.host;
    packet.address.port = ipAddress.port;

    while(!closeThread){

        if(!packetQueue.empty()){

            queueMtx.lock();

            BasePacket* basePacket = packetQueue.front().release();
            packetQueue.pop();

            queueMtx.unlock();

            packet.data = basePacket->getData();
            packet.len = basePacket->getSize();
            packet.maxlen = basePacket->getSize();

            if(SDLNet_UDP_Send(udpSocket,-1,&packet) <= 0){
                connectionGood = false;
            }

            packet.data = nullptr;

            delete basePacket;

        }
    }

    std::cout << "UDP thread closed" << std::endl;



}
