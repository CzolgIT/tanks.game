#ifndef TankSprite_h
#define TankSprite_h

#include "Main.h"

class TankSprite
{
public:
    
    TankSprite( SDL_Renderer* r );
    void draw( int x , int y , int dir , int dirT );
    
private:
    
    SDL_Renderer* renderer;
    
    Sprite* spriteTrackLeft;
    Sprite* spriteTrackRight;
    Sprite* spriteBody;
    Sprite* spriteTower;
    Sprite* spriteBarrel;
    
};

#endif /* TankSprite_h */
