#include "Main.h"

Text::Text( SDL_Renderer* r , std::string f )
{
    TTF_Init();
    
    renderer = r;
    fontPath = f;
    
    // default values
    size = 32;
    color = { 0, 0, 0 };
    //align = false; // TODO: alignment

    newCollection();
}

Text::~Text()
{
    TTF_Quit();
}

void Text::draw( std::string str , int x , int y )
{
    int posx=x;
    int posy=y;
    for ( int i = 0 ; i < str.length() ; i++ )
    {
        letter[str[i]][size][color.r][color.g][color.b]->render( renderer , posx , posy );
        posx += letter[str[i]][size][color.r][color.g][color.b]->getWidth();
    }
}

void Text::setSize( int s )
{
    size = s;
    if ( letter[64][size][color.r][color.g][color.b] == NULL )
        newCollection();

}

void Text::setColor( SDL_Color c )
{
    color = c;
    if ( letter[64][size][color.r][color.g][color.b] == NULL )
        newCollection();

}

void Text::newCollection()
{
    std::string str="x";
    TTF_Font* font = TTF_OpenFont( fontPath.c_str() , size );
    for ( int i = 32 ; i <127 ; i++ )
    {
        str[0] = (char)i;
        letter[i][size][color.r][color.g][color.b] = new Texture;
        letter[i][size][color.r][color.g][color.b]->loadFromRenderedText( renderer , font , str , color );
        std::cout << str ;
    }
    TTF_CloseFont( font );
}
