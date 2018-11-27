#include <utility>

#include "Main.h"

Button::Button( std::string name, int x, int y, float scale, bool center=false)
{
    this->name = std::move(name);
    this->x = x;
    this->y = y;
    this->scale = scale;
    this->center = center;
    this->clip = new SDL_Rect{0,0,Game::textureManager->button->getWidth(),Game::textureManager->button->getHeight()};
}

void Button::draw(bool active)
{
    if (center)
        Game::textureManager->button->render( x - (int)((float)clip->w*scale/170) , y , clip ,0 , nullptr , SDL_FLIP_NONE , scale/85 );
    else
        Game::textureManager->button->render( x , y , clip ,0 , nullptr , SDL_FLIP_NONE , scale );

    if (active)
        Game::textManager->draw( std::string("- ")+ name +std::string(" -") , x , y+scale , 1.7*scale, C_WHITE, true );
    else
        Game::textManager->draw( name , x , y+scale , 1.7*scale, C_WHITE, true );
}