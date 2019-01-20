#pragma once
#include "Main.h"

class Player: public _GameObject
{
public:

    Player( int id = 0, std::string nickname = "default" ) ;
    void handleEvent( SDL_Event& e );
    void move();
    void draw( int x0 , int y0 );
    void drawInfo( int x0 , int y0 );
    int getId();
    std::string getNickname();

    int getTowDir();
    int getDir();
    SDL_Point shootPosition();
    SDL_Point smokePosition();
    void reloadGUI();

    void simulate();

    void PushOut(Vector2D vec);

    void setPosition(SDL_Point position);
    void setDirection(int direction);
    void setTowerDirection(int towerDirection);

    void setTankSpeed(int tankSpeed);
    void setRotationSpeed(int rotationSpeed);
    void setTurretRotationSpeed(int turretRotationSpeed);

    void setFromPacket( CurrentPositionPacket * packet );

    int getTankSpeed();
    float getTowerSpeed();

    void setActualHp(int actualHp);

private:

    int id;
    std::string nickname;

    int actualHp;

    Vector2D blocked;

    float xFloat , yFloat;

    int tankSpeed , rotationSpeed , turretRotationSpeed;

    float moveSpeed , directionSpeed , towerSpeed;
    float directionFloat , towerDirection;
    int iTowerDirection; // net optimized

    TankSprite* sprite;
};
