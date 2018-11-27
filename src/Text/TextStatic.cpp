#include "Main.h"

TextStatic::TextStatic(std::string str, int x, int y, int size, SDL_Color color)
{
    this->x = x;
    this->y = y;
    this->texture = new Texture();
    TTF_Font* font = TTF_OpenFont( "assets/font.ttf" , size );
    this->texture->loadFromRenderedText( font , str , color );
    TTF_CloseFont( font );
}
void TextStatic::draw()
{
    texture->render( x - texture->getWidth()/2 , y );
}