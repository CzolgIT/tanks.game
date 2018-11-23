#include "Main.h"

NetManager::NetManager()
{
    SDLNet_Init();
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
