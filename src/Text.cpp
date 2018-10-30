#include "Main.h"

Text::Text( SDL_Renderer* r , std::string f )
{
    TTF_Init();
    
    renderer = r;
    fontPath = f;
    
    // default values
    size = 32;
    color = { 0, 0, 0 };
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
    
    if (align == true)
        posx -= (getWidth( str )/2);
    int posy = y;
    for ( int i = 0 ; i < str.length() ; i++ )
    {
        letter[str[i]][size]->render( renderer , posx , posy );
        posx += letter[str[i]][size]->getWidth();
    }
}

void Text::setSize( int s )
{
    size = s;
    if ( letter[64][size] == NULL )
        newCollection();
}

void Text::setColor( SDL_Color c )
{
    color = c;
    if ( letter[64][size] == NULL )
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
    for ( int i = 0 ; i < str.length() ; i++ )
    {
        width += letter[str[i]][size]->getWidth();
    }
    return width;
}
