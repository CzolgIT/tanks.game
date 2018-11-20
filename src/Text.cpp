#include <utility>

#include "Main.h"

Text::Text( SDL_Renderer* r , std::string f )
{
    TTF_Init();

    renderer = r;
    fontPath = std::move(f);
    // default values
    size = 32;
    color = { 55, 0, 0 };
    align = false;

    newCollection();
}

Text::~Text()
{
    TTF_Quit();
}

void Text::draw( std::string str , int x , int y )
{
    int posx = x;
    if (align)
        posx -= (getWidth( str )/2);
    int posy = y;
    for (char i : str) {
        letter[(int) i][size]->render( renderer , posx , posy );
        posx += letter[(int) i][size]->getWidth();
    }
}

void Text::setSize( int s )
{
    size = s;
    if ( letter[64][size] == nullptr )
        newCollection();
}

void Text::setColor( SDL_Color c )
{
    color = c;
    if ( letter[64][size] == nullptr )
        newCollection();
}

void Text::setAlignment( bool a )
{
    align = a;
}

void Text::newCollection()
{
    std::string str="x";
    TTF_Font* font = TTF_OpenFont( fontPath.c_str() , size );
    for ( int i = 32 ; i <127 ; i++ )
    {
        str[0] = (char)i;
        letter[i][size] = new Texture;
        letter[i][size]->loadFromRenderedText( renderer , font , str , color );
    }
    TTF_CloseFont( font );
}

int Text::getWidth( std::string str )
{
    int width = 0;
    for (char i : str)
        width += letter[(int) i][size]->getWidth();
    return width;
}
