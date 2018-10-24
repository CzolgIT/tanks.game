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
    texture->render( renderer , x, y , &clip );
    texture->render( renderer , x+512, y , &clip );
    texture->render( renderer , x+1024, y , &clip );
    texture->render( renderer , x+1536, y , &clip );
    
    texture->render( renderer , x, y+512 , &clip );
    texture->render( renderer , x+512, y+512 , &clip );
    texture->render( renderer , x+1024, y+512 , &clip );
    texture->render( renderer , x+1536, y+512 , &clip );
    
    texture->render( renderer , x, y+1024 , &clip );
    texture->render( renderer , x+512, y+1024 , &clip );
    texture->render( renderer , x+1024, y+1024 , &clip );
    texture->render( renderer , x+1536, y+1024 , &clip );
    
    texture->render( renderer , x, y+1536 , &clip );
    texture->render( renderer , x+512, y+1536 , &clip );
    texture->render( renderer , x+1024, y+1536 , &clip );
    texture->render( renderer , x+1536, y+1536 , &clip );
}
