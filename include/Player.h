#pragma once
#include "Main.h"

class Player: public GameObject
{
public:

    Player( SDL_Renderer* r , Text* t , float x , float y , int color ) ;
    void handleEvent( SDL_Event& e );
    void move( float timeStep );
    void draw( int x0 , int y0 );
    int getTowDir();

    SDL_Point shootPosition();

    void PushOut(Vector2D vec)
    {
        blocked.x += vec.x;
        blocked.y += vec.y;
    }

private:

    float accelerate( int scanCode , float what , float from , float to , float timeStep );

    Text* text;

    Vector2D blocked;

    float moveSpeed , directionSpeed , towerSpeed;
    float direction , towerDirection;
    int iDirection , iTowerDirection; // net optimized

    TankSprite* sprite;
};

