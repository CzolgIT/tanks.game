#include "Main.h"

EventPacket::EventPacket() : BasePacket(PT_EVENT,EVENT_PACKET_SIZE)
{

}


void EventPacket::SetKeys(bool keys[4])
{
    data[1] = keys[0];
    data[2] = keys[1];
    data[3] = keys[2];
    data[4] = keys[3];
}

EventPacket::~EventPacket() = default;