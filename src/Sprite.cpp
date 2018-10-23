#include "Main.h"

Sprite::Sprite( SDL_Renderer* r , Texture* t , int x , int y , int w , int h , int xc , int yc )
{
    renderer = r;
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
    if (texture==NULL)
        printf("nic z tego");
    texture->render( renderer , x, y , &clip , angle - 90 , &center );
}
