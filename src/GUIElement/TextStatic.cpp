#include "Main.h"

TextStatic::TextStatic( std::string str , float y , float size , float shadow , float x )
{
    float j = float(Game::configuration->getDisplayMode()->h)/36;

    this->x = (x == -1) ? int(double(Game::configuration->getDisplayMode()->w)/2) : int(x);
    this->y = int(y*j);
    this->shadow = (shadow == -1) ? (int)((float)Game::configuration->getDisplayMode()->h/300) : int(j*shadow);
    this->black = new Texture();
    this->white = new Texture();
    TTF_Font* font = TTF_OpenFont( "assets/font.ttf" , int(size*j) );
    this->black->loadFromRenderedText( font , str , C_BLACK );
    this->white->loadFromRenderedText( font , str , C_WHITE );
    TTF_CloseFont( font );
}
void TextStatic::draw()
{
    black->render( x - (int)((float)black->getWidth()/2) + shadow , y + shadow );
    white->render( x - (int)((float)white->getWidth()/2) , y );
}