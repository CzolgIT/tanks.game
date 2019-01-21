#include "Main.h"

NetManager::NetManager() : senderThread(nullptr)
{
    SDLNet_Init();
    connected = false;
    netPlayer = new NetPlayer();
}

NetManager::~NetManager() {

    closeSenderThread = true;
    if(senderThread)
        senderThread->join();


}

bool NetManager::disconnectPlayer() {

    if (isConnected())
        return tcpConnection.disconnectFromServer(netPlayer);
    else
        return false;
}

bool NetManager::isConnected(){
    return !(!tcpConnection.isConnectionGood() || !udpConnection.isConnectionGood());
}

bool NetManager::connect(std::string host, Uint16 port, Uint32 &globalTime) {
    std::cout << "Creating TCP connection" << std::endl;
    if (!tcpConnection.connectToServer(netPlayer, host, port))
    {
        std::cout << "Couldn't connect TCP" << std::endl;
        return false;
    }
    if(!udpConnection.connectToServer(host,port))
    {
        std::cout << "Couldn't connect UDP" << std::endl;
        return false;
    }

    std::cout << "Made TCP and UDP connections" << std::endl;

    tcpConnection.startSenderThread();
    udpConnection.startSenderThread();

    SDL_Delay(3000);
    getAllPlayersData();

    if(!syncTimeWithServer(netPlayer, globalTime))
    {
        std::cout << "Couldn't sync with server" << std::endl;
        return false;
    }
    std::cout << "Synced with server" << std::endl;

    clientsMap[getMyId()] = Game::configuration->getNickname();
    netPlayer->nickname = Game::configuration->getNickname();
    getMap();
    return isConnected();
}

void NetManager::getMap(){
    InfoRequestPacket * irpacket = new InfoRequestPacket();
    irpacket->setRequested(RequestType::RT_MAP_DATA);
    tcpConnection.addPacketToQueue(irpacket);

    float timeOut = 1000;

    while (true) {
        read();
        if (canPollPacket()) {
            BasePacket *received = pollPacket();
            if (received->getType() == PT_MAP_INFO) {
                std::cout << "Got map packet" << std::endl;
                MapDataPacket *m = (MapDataPacket *) received;
                strcpy(MpManager::map->characters, m->getMapData());
                std::cout << MpManager::map->characters << std::endl;
                break;
            }
        }
        if (timeOut < 0)
            break;

        timeOut--;
        SDL_Delay(10);
        std::cout << timeOut << std::endl;
    }

}


void NetManager::read() {

    bool udpPacketAvailable = true;
    while(udpPacketAvailable){
        BasePacket* received = udpConnection.getNextPacket();

        if(received != nullptr)
            packetQueue.push(received);
        else
            udpPacketAvailable = false;
    }

    bool tcpPacketAvailable = true;
    while(tcpPacketAvailable){
        BasePacket* received = tcpConnection.getNextPacket();
        if(received != nullptr){
            packetQueue.push(received);
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

bool NetManager::syncTimeWithServer(NetPlayer *player, Uint32 &globalTime) {
    std::cout << "Attempting time sync with server " << std::flush;
    Uint32 syncStartTime = SDL_GetTicks();
    Uint32 currentTime = syncStartTime;
    Uint32 hearbeatTime = 1000;
    BasePacket* received = nullptr;
    while(true){

        if(currentTime - syncStartTime > 99999999){
            std::cout << "\nCould not sync time with server" << std::endl;
            return false;
        }
        if(hearbeatTime>=1000)
        {

            std::cout << "+" << std::endl;
            udpConnection.addPacketToQueue(new HeartbeatPacket(player->id));
            hearbeatTime-=1000;

        }

        read();

        if (canPollPacket())
        {
            received = pollPacket();
            if (received->getType() == PT_SYNC)
            {
                auto* packet = (SyncPacket*)received;
                if(packet->getMode() == SYNC_RETURN){
                    udpSend(received);
                }
                else if(packet->getMode() == SYNC_SET){
                    globalTime = packet->getTime();
                    break;
                }
            }
        }

        hearbeatTime += SDL_GetTicks() - currentTime;
        currentTime = SDL_GetTicks();
    }
    std::cout << "Server set global time to: " << globalTime << "ms" << std::endl;
    setGlobalTime(globalTime);
    return true;
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

bool NetManager::canPollPacket()
{
    return !packetQueue.empty();
}

BasePacket* NetManager::pollPacket()
{
    if(!packetQueue.empty())
    {
        BasePacket* packet = packetQueue.front();
        packetQueue.pop();
        return packet;
    }
    else
        return nullptr;
}

Uint32 NetManager::getGlobalTime() {
    return globalTime;
}

void NetManager::setGlobalTime(Uint32 newGlobalTime) {
    this->globalTime = newGlobalTime;
}

void NetManager::clear()
{
    std::queue<BasePacket*>().swap( packetQueue );
}

int NetManager::getMyId()
{
    return netPlayer->id;
}

void NetManager::getAllPlayersData()
{
    read();
    while(canPollPacket())
    {
        BasePacket* received = pollPacket();
        if (received->getType() == PT_PLAYER_JOINED)
        {
            auto *p = (PlayerJoinedPacket *)received;
            p->print();
            clientsMap[(int)p->getId()] = p->getNickname();
        }
        else if (received->getType() == PT_PLAYER_DISCONNECTED)
        {
            auto *p = (PlayerDisconnectedPacket *)received;
            p->print();
            clientsMap.erase(p->getId());
        }
    }
}

std::string NetManager::getMyNickname() {
    return netPlayer->nickname;
}
