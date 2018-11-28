#include "Main.h"

TextStatic::TextStatic( std::string name , float x , float y , float size , float shadow ) : _Element( name , x , y )
{
    this->shadow = (shadow == -1) ? (int)((float)Game::configuration->getDisplayMode()->h/300) : int(yScale*shadow);
    this->black = new Texture();
    this->white = new Texture();
    TTF_Font* font = TTF_OpenFont( "assets/font.ttf" , int(size*yScale) );
    this->black->loadFromRenderedText( font , name , C_BLACK );
    this->white->loadFromRenderedText( font , name , C_WHITE );
    TTF_CloseFont( font );
}
void TextStatic::draw()
{
    black->draw(x*xScale - (int) ((float) black->getWidth() / 2) + shadow, y*yScale + shadow);
    white->draw(x*xScale - (int) ((float) white->getWidth() / 2), y*yScale);
}