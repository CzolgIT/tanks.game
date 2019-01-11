#ifndef SERVERTANKSGAME_PLAYERDISCONNECTEDPACKET_H
#define SERVERTANKSGAME_PLAYERDISCONNECTEDPACKET_H

#include "Main.h"

#define PLAYERDISCONNECTED_PACKET_SIZE (1+1)

class PlayerDisconnectedPacket : public BasePacket {

public:
    PlayerDisconnectedPacket();
    PlayerDisconnectedPacket(Uint8 id);

    void setId(Uint8 id);
    void print() const override;
    int getId();

};


#endif //SERVERTANKSGAME_PLAYERDISCONNECTEDPACKET_H
