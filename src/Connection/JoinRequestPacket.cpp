#include "Main.h"

JoinRequestPacket::JoinRequestPacket(std::string nickname):BasePacket(PT_JOIN_REQUEST, JOINREQUEST_PACKET_SIZE)
{
    for(int i=1; i<10; i++){
        data[i] = (Uint8)0;
    }
    for(int i=0; i<nickname.size(); i++){
        data[i+1] = (Uint8)nickname[i];
    }
}
