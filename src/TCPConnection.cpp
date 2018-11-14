#include "Main.h"

TCPConnection::TCPConnection() :
senderThread(nullptr)
{
    close_thread = false;
    
    socketSet = SDLNet_AllocSocketSet(1);
}

TCPConnection::~TCPConnection()
{
    close_thread = true;
    if(senderThread)
        senderThread->join();
    
    SDLNet_FreeSocketSet(socketSet);
}

bool TCPConnection::connectToServer(std::string host, Uint16 port)
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
        std::cerr << "SDLNet_TCP_Open error: " << SDLNet_GetError() << std::endl;
        return false;
    }
    
    std::cout << "Estabilished connection, requesting join...\n";
    
    JoinRequestPacket request;
    
    // Send request packet to the server
    SDLNet_TCP_Send(socket, request.getData(), request.getSize());
    
    JoinResponsePacket response;
    
    //read the response
    if(SDLNet_TCP_Recv(socket, response.getData(),response.getSize()) <= 0)
    {
        std::cerr << "SDLNet_TCP_Recv error: " << SDLNet_GetError( ) << std::endl;
        return false;
    }
    
    if(response.getResponse() == JR_REJECT)
    {
        std::cout << "Your connection was rejected by the server\n";
        return false;
    }
    
    std::cout << "The connection to the server was succesful! : O\n";
    
    return true;
    
    
}
