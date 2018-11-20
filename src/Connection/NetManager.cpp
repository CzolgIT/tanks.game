#include "Main.h"

NetManager::NetManager()
{
    SDLNet_Init();
}

bool NetManager::activate()
{
    if ( tcpConnection.connectToServer( SERVERIP , SERVERPORT ) )
        connected = true;
    else
        connected = false;
    return connected;
}

bool NetManager::disconnectPlayer() {
    connected = false;
    return tcpConnection.disconnectFromServer();
}

bool NetManager::isConnected(){
    return connected;
}
