#include "Main.h"

UniversalPacket::UniversalPacket():
    data(new Uint8[UNIVERSAL_PACKET_SIZE]()),
    size(UNIVERSAL_PACKET_SIZE)
{}

UniversalPacket::~UniversalPacket()
= default;

Uint8 * UniversalPacket::getData() const
{
  return data.get();  
}

unsigned int UniversalPacket::getSize() const
{
    return size;
}

std::unique_ptr<BasePacket> UniversalPacket::createFromContents()
{
    
    switch(data[0])
    {
        case PT_PLAYER_DISCONNECTED:
            return constructPacket(new PlayerDisconnectedPacket);
        case PT_SYNC:
            return constructPacket(new SyncPacket);
        case PT_HEARTBEAT:
            return constructPacket(new HeartbeatPacket);
        case PT_JOIN_REQUEST:
            return constructPacket(new JoinRequestPacket);
        case PT_JOIN_RESPONSE:
            return constructPacket(new JoinResponsePacket);
        case PT_CURRENT_POSITION:
            return constructPacket(new CurrentPositionPacket);
        case PT_PLAYER_JOINED:
            return constructPacket(new PlayerJoinedPacket);
        case PT_LAST_PLAYER_SENT:
            return constructPacket(new LastPlayerSentPacket);
        default:
            return nullptr;
    }
}

std::unique_ptr<BasePacket> UniversalPacket::constructPacket(BasePacket* packet)
{
    
    memcpy(packet->getData(), data.get(), packet->getSize());
    
    return std::unique_ptr<BasePacket>(packet);
    
    
}


