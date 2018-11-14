#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include "Main.h"

class TCPConnection {
public:
    TCPConnection();
    ~TCPConnection();
    
    bool connectToServer(std::string host, Uint16 port);
    
private:
    IPaddress ipAddress;
    TCPsocket socket;
    SDLNet_SocketSet socketSet;
    UniversalPacket uniPacket;
    std::thread* senderThread;
    std::atomic_bool close_thread;
    
};




#endif
