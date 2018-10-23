#include "Main.h"

Text::Text( SDL_Renderer* r , std::string f )
{
    renderer = r;
    fontPath = f;
    
    // default values
    size = 16;
    color = { 0, 0, 0 };
    align = false;
    
 //texture->loadFromRenderedText( renderer , font , newText , textColor );
}

void Text::draw( std::string str , int x , int y)
{
        //texture->render( renderer , x - texture->getWidth() / 2, y - texture->getHeight() / 2 );
}
