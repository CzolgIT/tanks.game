#ifndef CurrentPositionPacket_h
#define CurrentPositionPacket_h

#include "Main.h"

//(packet type + playerId + x + y + tankrot + turretrot + speed + rotspeed + turretspeed)
#define CURRENT_POSITION_PACKET_SIZE (1+1+2+2+2+2+2+2+2)

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

    Uint8 getPlayerId() const;
    Uint16 getX() const;
    Uint16 getY() const;
    Uint16 getTankRotation() const;
    Uint16 getTurretRotation() const;
    Uint16 getTankSpeed() const;
    Uint16 getRotationSpeed() const;
    Uint16 getTurretRotationSpeed() const;

    void print() const override;
};

#endif
