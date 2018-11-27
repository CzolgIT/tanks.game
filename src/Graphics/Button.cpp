#include <utility>

#include "Main.h"

Button::Button(SDL_Renderer *r, Texture *t, Text *text,std::string name, int x, int y, float scale, bool center=false)
{
    this->renderer = r;
    this->texture = t;
    this->text = text;
    this->name = std::move(name);
    this->x = x;
    this->y = y;
    this->scale = scale;
    this->center = center;
    this->clip = new SDL_Rect{0,0,texture->getWidth(),texture->getHeight()};
}

void Button::draw(bool active)
{
    if (center)
        texture->render( renderer , x - (int)((float)clip->w*scale/170) , y , clip ,0 , nullptr , SDL_FLIP_NONE , scale/85 );
    else
        texture->render( renderer , x , y , clip ,0 , nullptr , SDL_FLIP_NONE , scale );

    text->setColor( C_WHITE );
    text->setSize( int(1.7*scale) );

    if (active)
        text->draw( std::string("- ")+ name +std::string(" -") , x , y+scale );
    else
        text->draw( name , x , y+scale );
}