#include "Main.h"

NetManager::NetManager() : senderThread(nullptr)
{
    SDLNet_Init();
}

NetManager::~NetManager() {

    closeSenderThread = true;
    if(senderThread)
        senderThread->join();


}

bool NetManager::activate()
{
    connected = tcpConnection.connectToServer(SERVERIP , SERVERPORT );
    return connected;
}

bool NetManager::disconnectPlayer() {

    if (connected)
        return tcpConnection.disconnectFromServer();
    else
        return false;
}

bool NetManager::isConnected(){
    return connected;
}

bool NetManager::connect(Player &player, std::string host, Uint16 port, Uint32 &globalTime) {
    std::cout << "Creating TCP connection" << std::endl;
    if (tcpConnection.connectToServer())
}

void NetManager::read() {

}

void NetManager::tcpSend(BasePacket *packet) {

}

void NetManager::udpSend(BasePacket *packet) {

}

bool NetManager::syncTimeWithServer(const Player &player, Uint32 &globalTime) {
    return false;
}

void NetManager::startSenderThread() {

}

void NetManager::sendPackets() {

}


