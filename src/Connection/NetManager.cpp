#include "Main.h"

NetManager::NetManager()
{
    SDLNet_Init();
}

bool NetManager::activate()
{
    return tcpConnection.connectToServer( SERVERIP , SERVERPORT );
}

bool NetManager::disconnectPlayer() {
    return tcpConnection.disconnectFromServer();
}
