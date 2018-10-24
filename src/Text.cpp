#include "Main.h"

Text::Text( SDL_Renderer* r , std::string f )
{
    renderer = r;
    fontPath = f;
    
    // default values
    size = 16;
    color = { 0, 0, 0 };
    align = false;

    newSize(size);
}

void Text::draw( std::string str , int x , int y )
{
    int posx=x;
    int posy=y;
    for ( int i = 0 ; i < str.length() ; i++ )
    {
        letter[str[i]][size]->render( renderer , posx , posy );
        posx += letter[str[i]][size]->getWidth();
    }
}

void Text::newSize( int s )
{
    std::string str="x";
    TTF_Font* font = TTF_OpenFont( fontPath.c_str() , s );
    for ( int i = 32 ; i <127 ; i++ )
    {
        str[0] = (char)i;
        letter[i][s] = new Texture;
        letter[i][s]->loadFromRenderedText( renderer , font , str , color );
        std::cout << str ;
    }
    TTF_CloseFont( font );
}
