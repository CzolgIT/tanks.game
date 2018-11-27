#include "Main.h"

Letter::Letter( char character , std::string path , SDL_Color color , int size )
{
    this->character = character;
    this->texture = new Texture();
    TTF_Font* font = TTF_OpenFont( path.c_str() , size );
    this->texture->loadFromRenderedText( font , character , color );
    TTF_CloseFont( font );
}

char Letter::getCharacter()
{
    return character;
}
int Letter::getWidth()
{
    return texture->getWidth();
}
void Letter::draw( int x , int y )
{
    texture->render( x , y );
    //std::cout<<character;
}