//
// Created by inql on 09.01.19.
//

#ifndef SERVERTANKSGAME_BULLETINFOPACKET_H
#define SERVERTANKSGAME_BULLETINFOPACKET_H

#include "Main.h"
#define BULLET_INFO_PACKET_SIZE (1+1+1+2+2+2)
class BulletInfoPacket : public BasePacket
{
public:

    BulletInfoPacket();
    void setPlayerId(Uint8 playerId);
    void setBulletId(Uint8 bulletId);
    void setX(Uint16 x);
    void setY(Uint16 y);
    void setAngle(Uint16 angle);

    Uint8 getPlayerId() const;
    Uint8 getBulletId() const;
    Uint16 getX() const;
    Uint16 getY() const;
    Uint16 getAngle() const;

    void print() const override;
};

#endif //SERVERTANKSGAME_BULLETINFOPACKET_H
