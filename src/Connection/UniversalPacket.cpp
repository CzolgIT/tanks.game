#include "Main.h"

UniversalPacket::UniversalPacket():
    data(new Uint8[UNIVERSAL_PACKET_SIZE]()),
    size(UNIVERSAL_PACKET_SIZE)
{}

UniversalPacket::~UniversalPacket()
= default;

Uint8 * UniversalPacket::getData() const
{
  return data;
}

unsigned int UniversalPacket::getSize() const
{
    return size;
}

BasePacket* UniversalPacket::createFromContents()
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
            return constructPacket(new JoinRequestPacket(""));
        case PT_JOIN_RESPONSE:
            return constructPacket(new JoinResponsePacket);
        case PT_CURRENT_POSITION:
            return constructPacket(new CurrentPositionPacket);
        case PT_PLAYER_JOINED:
            return constructPacket(new PlayerJoinedPacket);
        case PT_BULLET_INFO:
            return constructPacket(new BulletInfoPacket);
        case PT_MAP_INFO:
            return constructPacket(new MapDataPacket);
        case PT_PLAYER_READY:
            return constructPacket(new PlayerReadyPacket);
        case PT_PLAYER_DEAD:
            return constructPacket(new PlayerDeadPacket);
        case PT_POWERUP:
            return constructPacket(new PowerUpPacket);
        default:
            return nullptr;
    }
}

BasePacket* UniversalPacket::constructPacket(BasePacket* packet)
{
    memcpy(packet->getData(), data, packet->getSize());
    return packet;
}


