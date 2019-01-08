#include "Main.h"

TCPConnection::TCPConnection() :
senderThread(nullptr)
{
    closeThread = false;
    socketSet = SDLNet_AllocSocketSet(1);
}

TCPConnection::~TCPConnection()
{
    closeThread = true;
    if(senderThread)
        senderThread->join();
    
    SDLNet_FreeSocketSet(socketSet);
}

bool TCPConnection::connectToServer(NetPlayer* player, std::string host, Uint16 port)
{
    // Resolve the server name
    if (SDLNet_ResolveHost(&ipAddress, host.c_str(), port))
    {
        std::cerr << "SDLNet_ResolveHost(" << host << ", " << port << ") error: "
            << SDLNet_GetError() << std::endl;
        return false;
    }
    // Establish connection
    socket = SDLNet_TCP_Open(&ipAddress);
    if(!socket){
        std::cout << "wrong adress: "<< host << " : " << port << "\n";
        //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"SDLNet_TCP_Open error\n",SDLNet_GetError(),nullptr);
        //std::cerr << "SDLNet_TCP_Open error: " << SDLNet_GetError() << "\n";
        return false;
    }

    std::cout << "Established connection with server: " << SERVERIP << " : " << SERVERPORT << ", requesting join...\n";
    
    JoinRequestPacket request;
    
    // Send request packet to the server
    SDLNet_TCP_Send(socket, request.getData(), request.getSize());
    
    JoinResponsePacket response;
    
    //read the response
    if(SDLNet_TCP_Recv(socket, response.getData(),response.getSize()) <= 0)
    {
        std::cerr << "SDLNet_TCP_Received error: " << SDLNet_GetError( ) << std::endl;
        return false;
    }
    
    if(response.getResponse() == JR_REJECT)
    {
        std::cout << "Your connection was rejected by the server\n";
        return false;
    }
    if(response.getResponse() == JR_OK){
        std::cout << "The connection to the server was successful! : " << (int)response.getId() << "\n";
//        setId(response.getId());
        player->id = (Uint8)(int)response.getId();
        std::cout << "X" <<  (int)player->id << "D" << std::endl;
        SDLNet_TCP_AddSocket(socketSet,socket);
        connectionGood = true;
        return true;

    }
    return false;

    
}

void TCPConnection::sendPackets() {
    while(!closeThread){

        if(!packetQueue.empty()){
            queueMtx.lock();

            std::unique_ptr<BasePacket> packet = std::move(packetQueue.front());
            packetQueue.pop();

            queueMtx.unlock();

            if(SDLNet_TCP_Send(socket,packet->getData(),packet->getSize()) < (int)packet->getSize()){
                connectionGood = false;
            }
        }


    }

    std::cout << "TCP thread closed" << std::endl;
}

bool TCPConnection::disconnectFromServer(NetPlayer* player) {
    PlayerDisconnectedPacket playerDisconnectedPacket((Uint8)(int)player->id);
    if(SDLNet_TCP_Send(socket,playerDisconnectedPacket.getData(),playerDisconnectedPacket.getSize())>0){
        std::cout << "Player o ID: " << (int)(player->id) << " wysłał zapytanie do opuszczenia serwera" << std::endl;
    }
    return true;
}

void TCPConnection::sendPacket() {

    if(!packetQueue.empty()){
        queueMtx.lock();

        //remove the packet
        std::unique_ptr<BasePacket> packet = std::move(packetQueue.front());
        packetQueue.pop();

        queueMtx.unlock();

        //send the front packet

        if(SDLNet_TCP_Send(socket,packet->getData(),packet->getSize())<(int)packet->getSize()){
            connectionGood = false;
        }
    }


}

std::unique_ptr<BasePacket> TCPConnection::getNextPacket() {

    //check the sockets for readiness

    if(SDLNet_CheckSockets(socketSet,0)>0){
        if(SDLNet_SocketReady(socket)){

            //read the first byte
            if(SDLNet_TCP_Recv(socket,uniPacket.getData(),1)>0){

                //read first byte

                int bytesRemaining;
                switch(*uniPacket.getData())
                {
                    case PT_JOIN_REQUEST:
                        bytesRemaining = JOINREQUEST_PACKET_SIZE - 1;
                        break;
                    case PT_JOIN_RESPONSE:
                        bytesRemaining = JOIN_RESPONSE_PACKET_SIZE - 1;
                        break;
                    case PT_PLAYER_DISCONNECTED:
                        bytesRemaining = PLAYERDISCONNECTED_PACKET_SIZE -1;
                        break;
                    default:
                        std::cout<<"TCP unknown packet size!"<<std::endl;
                        bytesRemaining = uniPacket.getSize() -1;
                        break;
                }

                //rest of the packet
                Uint8* packetContents = uniPacket.getData();
                packetContents++;
                if(SDLNet_TCP_Recv(socket,packetContents,bytesRemaining)<0){
                    std::cout << "TCP could not get packet contents" << std::endl;
                }

                std::unique_ptr<BasePacket> received = uniPacket.createFromContents();
                if(received){
                    return received;
                }
                else{
                    std::cout << "TCP Packet type not recognised" << std::endl;
                    return nullptr;
                }
            }
            else{
                std::cout << "SDLNet_TCP_Recv: " << SDLNet_GetError() << std::endl;
                connectionGood = false;
                return nullptr;
            }
        }
        else{
            return nullptr;
        }
    }
    else{
        return nullptr;
    }
}

void TCPConnection::startSenderThread() {

    if(senderThread == nullptr)
        senderThread = new std::thread(std::mem_fun(&TCPConnection::sendPackets),this);


}

void TCPConnection::addPacketToQueue(BasePacket *packet) {

    queueMtx.lock();
    packetQueue.push(std::unique_ptr<BasePacket>(packet));
    queueMtx.unlock();


}

bool TCPConnection::isConnectionGood() {
    return connectionGood;
}
