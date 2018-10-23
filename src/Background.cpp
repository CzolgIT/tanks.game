#include "Main.h"

Background::Background( SDL_Renderer* r )
{
    renderer = r;
    width=0;
    height=0;
}

void Background::loadFromTexture( Texture* t , int x , int y , int w , int h )
{
    texture = t;
    clip.x = x;
    clip.y = y;
    clip.w = w;
    clip.h = h;
    width = w;
    height = h;
}

void Background::draw( float x , float y )
{
    texture->render( renderer , x, y , &clip );
}
