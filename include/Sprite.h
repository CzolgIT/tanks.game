#ifndef Sprite_h
#define Sprite_h

#include "Main.h"

class Sprite
{
public:
    
    Sprite( SDL_Renderer* r , Texture* t , int x , int y , int w , int h , int xc , int yc );
    void draw( float x , float y , double angle = 0.0 );

private:
    
    SDL_Renderer* renderer;
    Texture* texture;
    SDL_Rect clip;
    SDL_Point center;
    
};

#endif /* Sprite_h */
