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

    this->textb = new TextStatic( this->name , x , y + scale + scale/10 , 1.6*scale , C_BLACK );
    this->textw = new TextStatic( this->name , x-scale/10 , y + scale-scale/10 + scale/10 , 1.6*scale , C_WHITE );

    this->textActiveb = new TextStatic( "+ " + this->name + " +" , x , y + scale , 1.7*scale , C_BLACK );
    this->textActivew = new TextStatic( "+ " + this->name + " +" , x-scale/10 , y + scale-scale/10 , 1.7*scale , C_WHITE );
}

void Button::draw(bool active) {
    if (center)
        Game::textureManager->button->render(x - (int) ((float) clip->w * scale / 170), y, clip, 0, nullptr, SDL_FLIP_NONE, scale / 85);
    else
        Game::textureManager->button->render(x, y, clip, 0, nullptr, SDL_FLIP_NONE, scale);

    if (active)
    {
        textActiveb->draw();
        textActivew->draw();
    }
    else
    {
        textb->draw();
        textw->draw();
    }


}