#include "Main.h"

Text::Text( SDL_Renderer* r , std::string newText , TTF_Font* font )
{
    renderer = r;
    textColor = { 0, 0, 0 };
    texture = new Texture( renderer );
    
    textString = newText;
    texture->loadFromRenderedText( renderer , font , newText , textColor );
}

void Text::draw( int x , int y , bool center )
{
    if ( center == true)
        texture->render( renderer , x - texture->getWidth() / 2, y - texture->getHeight() / 2 );
    else
        texture->render( renderer , x , y - texture->getHeight() / 2 );
}
