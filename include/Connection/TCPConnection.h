#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include "Main.h"

class TCPConnection {
public:
    TCPConnection();
    ~TCPConnection();
    
    bool connectToServer(std::string host, Uint16 port);
    void setId(Uint8 givenId);
    Uint8 getId();
    bool disconnectFromServer();
    
private:
    IPaddress ipAddress;
    TCPsocket socket;
    SDLNet_SocketSet socketSet;
    UniversalPacket uniPacket;
    std::thread* senderThread;
    std::atomic_bool close_thread;
    Uint8 id;
    
};




#endif
