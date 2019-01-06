#ifndef TankSprite_h
#define TankSprite_h

#include "Main.h"

class TankSprite
{
public:

    explicit TankSprite( int color = 1);
    void draw( SDL_Point position , int dir , int dirT , int move );
    
private:

    Sprite* spriteBarrel;
    Sprite* spriteBody;
    Sprite* spriteTower;
    Sprite* spriteTracks[5];

    int step;
};

#endif
