#ifndef CurrentPositionPacket_h
#define CurrentPositionPacket_h

#include "Main.h"

//(packet type + playerId + x + y + tankrot + turretrot + speed + rotspeed + turretspeed + actualhp + stats)
#define CURRENT_POSITION_PACKET_SIZE (1+1+2+2+2+2+2+2+2+1+2)

class CurrentPositionPacket : public BasePacket{
public:
    CurrentPositionPacket();

    void setPlayerId(Uint8 playerId);
    void setX(Uint16 x);
    void setY(Uint16 y);
    void setTankRotation(Uint16 tankRotation);
    void setTurretRotation(Uint16 turretRotation);
    void setTankSpeed(Uint16 tankSpeed);
    void setRotationSpeed(Uint16 rotationSpeed);
    void setTurretRotationSpeed(Uint16 turretRotationSpeed);
    void setActualHp(Uint8 actHp);

    int getPlayerId() const;
    int getX() const;
    int getY() const;
    int getTankRotation() const;
    int getTurretRotation() const;
    int getTankSpeed() const;
    int getRotationSpeed() const;
    int getTurretRotationSpeed() const;
    int getActualHp() const;
    int getScore() const;
    int getDeaths() const;

    void print() const override;
};

#endif
