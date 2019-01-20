#include "Main.h"

CurrentPositionPacket::CurrentPositionPacket():BasePacket(PT_CURRENT_POSITION,CURRENT_POSITION_PACKET_SIZE) {}

void CurrentPositionPacket::setPlayerId(Uint8 playerId) { data[1] = playerId; }
void CurrentPositionPacket::setX(Uint16 x) { SDLNet_Write16(x, &data[2]); }
void CurrentPositionPacket::setY(Uint16 y) { SDLNet_Write16(y, &data[4]); }
void CurrentPositionPacket::setTankRotation(Uint16 tankRotation) { SDLNet_Write16(tankRotation, &data[6]); }
void CurrentPositionPacket::setTurretRotation(Uint16 turretRotation) { SDLNet_Write16(turretRotation, &data[8]); }
void CurrentPositionPacket::setTankSpeed(Uint16 tankSpeed) { SDLNet_Write16(tankSpeed, &data[10]); }
void CurrentPositionPacket::setRotationSpeed(Uint16 rotationSpeed) { SDLNet_Write16(rotationSpeed, &data[12]); }
void CurrentPositionPacket::setTurretRotationSpeed(Uint16 turretRotationSpeed) { SDLNet_Write16(turretRotationSpeed, &data[14]); }
void CurrentPositionPacket::setActualHp(Uint8 actHp) {data[16] = actHp;}

int CurrentPositionPacket::getPlayerId() const { return static_cast<int8_t>(data[1]); }
int CurrentPositionPacket::getX() const { return static_cast<int16_t>(SDLNet_Read16(&data[2])); }
int CurrentPositionPacket::getY() const { return static_cast<int16_t>(SDLNet_Read16(&data[4])); }
int CurrentPositionPacket::getTankRotation() const { return static_cast<int16_t>(SDLNet_Read16(&data[6])); }
int CurrentPositionPacket::getTurretRotation() const { return static_cast<int16_t>(SDLNet_Read16(&data[8])); }
int CurrentPositionPacket::getTankSpeed() const { return static_cast<int16_t>(SDLNet_Read16(&data[10])); }
int CurrentPositionPacket::getRotationSpeed() const { return static_cast<int16_t>(SDLNet_Read16(&data[12])); }
int CurrentPositionPacket::getTurretRotationSpeed() const { return static_cast<int16_t>(SDLNet_Read16(&data[14])); }
int CurrentPositionPacket::getActualHp() const { return static_cast<int16_t>(data[16]);}
int CurrentPositionPacket::getScore() const { return static_cast<int8_t>(data[17]);}
int CurrentPositionPacket::getDeaths() const { return static_cast<int8_t>(data[18]);}

void CurrentPositionPacket::print() const
{
    std::cout << "CurrentPositionPacketReceived:ID: " << (int)getPlayerId()
              << " X: " << (int)getX()
              << " Y: " << (int)getY()
              << " TankRot: " << (int)getTankRotation()
              << " TurretRot: " << (int)getTurretRotation()
              << " TankSpeed: " << (int)getTankSpeed()
              << " RotationSpeed: " << (int)getRotationSpeed()
              << " TurretRotationSpeed: " << (int)getTurretRotationSpeed()
              << std::endl;
}