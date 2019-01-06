#pragma once
#include "Main.h"

class Player: public _GameObject
{
public:

    Player( SDL_Point position , int color ) ;
    void handleEvent( SDL_Event& e );
    void move();
    void draw( int x0 , int y0 );

    int getTowDir();
    int getDir();
    SDL_Point shootPosition();
    SDL_Point smokePosition();

    void PushOut(Vector2D vec);



private:

    float accelerate( int scanCode , float what , float from , float to , float timeStep );

    Vector2D blocked;

    float xFloat , yFloat;

    float moveSpeed , directionSpeed , towerSpeed;
    float directionFloat , towerDirection;
    int iTowerDirection; // net optimized

    TankSprite* sprite;
};
