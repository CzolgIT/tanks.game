#include "Main.h"

TextStatic::TextStatic(std::string str, int x, int y, int size, int shadow)
{
    this->x = x;
    this->y = y;
    this->shadow = shadow;
    this->black = new Texture();
    this->white = new Texture();
    TTF_Font* font = TTF_OpenFont( "assets/font.ttf" , size );
    this->black->loadFromRenderedText( font , str , C_BLACK );
    this->white->loadFromRenderedText( font , str , C_WHITE );
    TTF_CloseFont( font );
}
void TextStatic::draw()
{
    black->render( x - (int)((float)black->getWidth()/2) + shadow , y + shadow );
    white->render( x - (int)((float)white->getWidth()/2) , y );
}