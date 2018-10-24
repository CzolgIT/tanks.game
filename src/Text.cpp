#include "Main.h"

Text::Text( SDL_Renderer* r , std::string f )
{
    renderer = r;
    fontPath = f;
    
    // default values
    size = 16;
    color = { 0, 0, 0 };
    align = false;
    
    font = TTF_OpenFont( fontPath.c_str() , 16 );
    newSize(size);
    
}

void Text::draw( std::string str , int x , int y)
{
    std::cout << "dlugosc tekstu ktory chcesz otrzymac: " << str.length() << "\n";
}


void Text::newSize( int s )
{
    std::string str="xh";
    //TTF_Font* font = TTF_OpenFont( fontPath.c_str() , s );
    for ( int i = 32 ; i <127 ; i++ )
    {
        //str[0] = (char)i;
        letter[i][s] = new Texture;
        //letter[i][s]->loadFromRenderedText( renderer , font , "wtf" , color );
    }
}
