#ifndef NetManager_h
#define NetManager_h

#include "Main.h"

class NetManager
{
public:
    NetManager();
    
    void activate( std::string ip = "153.19.7.230" , int port = 7777);
    void close();
    
    void getMessage();
    void sendMessage( char* slowo );

private:

    UDPsocket socket;
    UDPpacket* packet;
    UDPpacket* packet2;
    IPaddress destAddress;
    TCPConnection tcpConnection;
};

#endif /* NetManager_h */




