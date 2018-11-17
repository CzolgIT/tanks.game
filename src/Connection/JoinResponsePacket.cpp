#include "Main.h"

JoinResponse JoinResponsePacket::getResponse() const
{
    return (JoinResponse)data[1];
}

Uint8 JoinResponsePacket::getId() const {
    return (Uint8)data[2];
}
