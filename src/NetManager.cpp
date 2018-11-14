#include "Main.h"

NetManager::NetManager()
{
    SDLNet_Init();
}

void NetManager::activate()
{
    tcpConnection.connectToServer( SERVERIP , SERVERPORT );
}
