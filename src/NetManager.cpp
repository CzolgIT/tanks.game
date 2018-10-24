#include "Main.h"

NetManager::NetManager()
{
    SDLNet_Init();
}

NetManager::~NetManager()
{
    SDLNet_FreePacket( packet );
    SDLNet_FreePacket( packet2 );
    SDLNet_Quit();
}

void NetManager::activate( std::string ip , int port )
{
    socket = SDLNet_UDP_Open( CLIENTPORT );
    packet = SDLNet_AllocPacket(256);
    packet2 = SDLNet_AllocPacket(256);
    
    SDLNet_ResolveHost( &destAddress, ip.c_str(), port );
    
    packet->address.host = destAddress.host;
    packet->address.port = destAddress.port;
}

void NetManager::getMessage()
{
    int recv_result = SDLNet_UDP_Recv( socket, packet2 );
    if( recv_result > 0 )
    {
        //printf("Received data from %s:%i", SDLNet_ResolveIP(&packet2->address), SDLNet_Read16(&packet2->address.port));
        printf( "\nInfo from server: x=%d\n", packet2->data[0] );
    }
}

void NetManager::sendMessage( char* slowo )
{
    memcpy(packet->data, slowo, sizeof(*slowo) );
    packet->len = sizeof(slowo);
    
    SDLNet_UDP_Send( socket, -1, packet );
}
