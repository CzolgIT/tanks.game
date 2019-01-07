#ifndef Sprite_h
#define Sprite_h

#include "Main.h"

class Sprite
{
public:
    
    Sprite( Texture* texture , SDL_Rect clip , float scale=1 );
    void draw( SDL_Point position , int direction=0 );

private:

    Texture* texture;
    SDL_Rect clip;
    SDL_Point center;
    float scale;
    
};

#endif
