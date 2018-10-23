#ifndef NetManager_h
#define NetManager_h

#include "Main.h"

class NetManager
{
public:
    NetManager();
    
    void activate( std::string ip = "127.0.0.1" , int port = 1616);
    void close();
    
    void getMessage();
    void sendMessage( char* slowo );

private:
    UDPsocket socket;
    UDPpacket* packet;
    UDPpacket* packet2;
    IPaddress destAddress;
};

#endif /* NetManager_h */




