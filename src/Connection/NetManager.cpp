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
//    connected = tcpConnection.connectToServer(SERVERIP , SERVERPORT );
    return connected;
}

bool NetManager::disconnectPlayer(Player& player) {

    if (connected)
        return tcpConnection.disconnectFromServer(player);
    else
        return false;
}

bool NetManager::isConnected(){
    return !(!tcpConnection.isConnectionGood() || !udpConnection.isConnectionGood());
}

bool NetManager::connect(Player &player, std::string host, Uint16 port, Uint32 &globalTime) {
    std::cout << "Creating TCP connection" << std::endl;
    if (!tcpConnection.connectToServer(player,host,port))
        return false;

    if(!udpConnection.connectToServer(host,port))
        return false;

    //start different threads for every connection
    tcpConnection.startSenderThread();
    udpConnection.startSenderThread();

    //ping the server
    if(!syncTimeWithServer(player,globalTime))
        return false;

    //todo: do some stuff
    //todo: get room info & stuff

    return isConnected();
}

void NetManager::read() {

    // read all pending udp packets
    bool udpPacketAvailable = true;
    while(udpPacketAvailable){
        std::unique_ptr<BasePacket> received = udpConnection.getNextPacket();

        // if the packet was not null, add it to the queue
        if(received != nullptr)
            packetQueue.push(std::move(received));
        else
            udpPacketAvailable = false;
    }

    // read all pending tcp packets
    bool tcpPacketAvailable = true;
    while(tcpPacketAvailable){
        std::unique_ptr<BasePacket> received = tcpConnection.getNextPacket();
        if(received != nullptr){
            packetQueue.push(std::move(received));
        }
        else{
            tcpPacketAvailable = false;
        }
    }


}

void NetManager::tcpSend(BasePacket *packet) {
    tcpConnection.addPacketToQueue(packet);
}

void NetManager::udpSend(BasePacket *packet) {
    udpConnection.addPacketToQueue(packet);
}

bool NetManager::syncTimeWithServer(const Player &player, Uint32 &globalTime) {
    //todo: server sync
    return false;
}

void NetManager::startSenderThread() {

    if(senderThread == nullptr)
        senderThread = new std::thread(std::mem_fun(&NetManager::sendPackets),this);

}

void NetManager::sendPackets() {
    while(!closeSenderThread){
        tcpConnection.sendPacket();

        udpConnection.sendPacket();
    }
}


