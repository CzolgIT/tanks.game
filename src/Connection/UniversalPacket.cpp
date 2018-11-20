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
        default:
            return nullptr;
    }
}

std::unique_ptr<BasePacket> UniversalPacket::constructPacket(BasePacket* packet)
{
    
    memcpy(packet->getData(), data.get(), packet->getSize());
    
    return std::unique_ptr<BasePacket>(packet);
    
    
}


