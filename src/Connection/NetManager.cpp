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
    connected = false;
    return tcpConnection.disconnectFromServer();
}

bool NetManager::isConnected(){
    return connected;
}
