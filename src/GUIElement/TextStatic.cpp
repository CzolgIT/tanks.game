#include <utility>

#include "Main.h"

TextStatic::TextStatic( std::string name , float x , float y , float size , float shadow ) : _Element( name , x , y )
{
    this->size = size;
    this->shadow = shadow;
    loadTexture();
}
void TextStatic::draw()
{
    black->draw(int(x*xScale) + int((shadow == -1) ? yScale/9 : yScale*shadow), int(y*yScale) + int((shadow == -1) ? yScale/9 : yScale*shadow));
    white->draw(int(x*xScale) , int(y*yScale));
}
void TextStatic::drawInLine(int line)
{
    black->draw(int(x*xScale) + int((shadow == -1) ? yScale/9 : yScale*shadow), yScale*line + int(y*yScale) + int((shadow == -1) ? yScale/9 : yScale*shadow));
    white->draw(int(x*xScale) , yScale*line + int(y*yScale));
}
void TextStatic::updateScale()
{
    this->xScale = float(Game::configuration->getDisplayMode()->w)/64;
    this->yScale = float(Game::configuration->getDisplayMode()->h)/36;
    delete(this->black);
    delete(this->white);
    loadTexture();
}
void TextStatic::loadTexture()
{
    this->black = new Texture();
    this->white = new Texture();
    TTF_Font* font = TTF_OpenFont( "assets/font.ttf" , int(size*yScale) );
    this->black->loadFromRenderedText( font , name , C_BLACK );
    this->white->loadFromRenderedText( font , name , C_WHITE );
    this->black->setAlignCenter(true);
    this->white->setAlignCenter(true);
    TTF_CloseFont( font );
}

void TextStatic::setNewName(std::string nname)
{
    name = std::move(nname);
    free(white);
    free(black);
    loadTexture();
}