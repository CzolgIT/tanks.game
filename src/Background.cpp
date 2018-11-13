#include "Main.h"

Background::Background( SDL_Renderer* r )
{
    renderer = r;
    width=512;
    height=512;
    texture = new Texture( renderer , "assets/tex_map.png" );
    clip.x = 0;
    clip.y = 0;
    clip.w = width;
    clip.h = height;
}

void Background::draw( int x , int y )
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            texture->render( renderer , x+(i*512) , y+(j*512) , &clip );
}
