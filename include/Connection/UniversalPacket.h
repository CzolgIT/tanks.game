#ifndef UNIVERSAL_PACKET_H
#define UNIVERSAL_PACKET_H

#include "Main.h"

// Larger than the largest packet that will be received
#define UNIVERSAL_PACKET_SIZE 64*64+10

class UniversalPacket{
public:
    UniversalPacket();
    ~UniversalPacket();
    
    Uint8* getData() const;
    unsigned int getSize() const;
    
    BasePacket* createFromContents();
private:
    Uint8* data;
    unsigned int size;
    
    BasePacket* constructPacket(BasePacket* packet);
};


#endif
