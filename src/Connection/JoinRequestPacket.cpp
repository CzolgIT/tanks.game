#include "Main.h"

JoinRequestPacket::JoinRequestPacket(std::string nickname):BasePacket(PT_JOIN_REQUEST, JOINREQUEST_PACKET_SIZE)
{
    data[1] = (Uint8)nickname[0];
    data[2] = (Uint8)nickname[1];
    data[3] = (Uint8)nickname[2];
    data[4] = (Uint8)nickname[3];
    data[5] = (Uint8)nickname[4];
    data[6] = (Uint8)nickname[5];
    data[7] = (Uint8)nickname[6];
    data[8] = (Uint8)nickname[7];
    data[9] = (Uint8)nickname[8];
    data[10] = (Uint8)nickname[9];
}
