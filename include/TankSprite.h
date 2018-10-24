#ifndef TankSprite_h
#define TankSprite_h

#include "Main.h"

class TankSprite
{
public:
    
    TankSprite( SDL_Renderer* r , int color = 1);
    void draw( int x , int y , int dir , int dirT , int move );
    
private:
    
    SDL_Renderer* renderer;
    
    Sprite* spriteTrackLeft[5];
    Sprite* spriteTrackRight[5];
    Sprite* spriteBody;
    Sprite* spriteTower;
    Sprite* spriteBarrel;
    
    int step;
};

#endif /* TankSprite_h */
