#pragma once
#include "Main.h"

class Player: public _GameObject
{
public:

    Player( int color , int id = 0 ) ;
    void handleEvent( SDL_Event& e );
    void move();
    void draw( int x0 , int y0 );
    void drawInfo();

    int getTowDir();
    int getDir();
    SDL_Point shootPosition();
    SDL_Point smokePosition();

    void PushOut(Vector2D vec);

    void setPosition(SDL_Point position);
    void setDirection(int direction);
    void setTowerDirection(int towerDirection);

private:

    int id;

    Vector2D blocked;

    float xFloat , yFloat;

    float moveSpeed , directionSpeed , towerSpeed;
    float directionFloat , towerDirection;
    int iTowerDirection; // net optimized

    TankSprite* sprite;
};
