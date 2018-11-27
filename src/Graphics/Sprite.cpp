#include "Main.h"

Sprite::Sprite( Texture* t , int x , int y , int w , int h , int xc , int yc )
{
    texture = t;

    clip.x = x;
    clip.y = y;
    clip.w = w;
    clip.h = h;

    center.x = xc;
    center.y = yc;
}

void Sprite::draw( float x , float y , double angle )
{
    if (texture== nullptr )
        printf("nic z tego");
    texture->render( x, y , &clip , angle - 90 , &center , SDL_FLIP_NONE , TANKSCALE);
}
