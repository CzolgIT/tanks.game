#include <utility>

#include "Main.h"

Button::Button( std::string name, float yy, std::string comm, float xx, bool center)
{
    this->extended = (!comm.empty());
    this->scale = (int)((float)Game::configuration->getDisplayMode()->h/36);
    this->x = (xx == -1) ? float(Game::configuration->getDisplayMode()->w)/2 : x;
    this->y = yy;
    this->center = center;
    this->clip = new SDL_Rect{0,0,Game::textureManager->button->getWidth(),Game::textureManager->button->getHeight()};
    float add =0;

    if (!comm.empty())
    {
        add = (0.125);
        this->comment[0] = new TextStatic( comm , yy + 2 , 1 );
        this->comment[1] = new TextStatic( comm , yy + 1.9 , 1.1 );
        this->change[0] = new TextStatic( "<" , yy + 1.9 , 1 , -1 , x-scale*6 );
        this->change[1] = new TextStatic( ">" , yy + 1.9 , 1 , -1 , x+scale*6 );
    }
    this->text[0] = new TextStatic( name , yy + 0.9 -add*4 , 1.6-add );
    this->text[1] = new TextStatic( "+ " + name + " +" , yy + 0.8-add*4 , 1.7-add );

}

void Button::setComment( std::string str )
{
    if (extended)
    {
        delete(this->comment[0]);
        delete(this->comment[1]);
        this->comment[0] = new TextStatic( str , y + 1.9 , 1 );
        this->comment[1] = new TextStatic( str , y + 1.9 , 1.1 );
    }
}



void Button::draw(bool active , bool prev , bool next ) {
    if (center)
        Game::textureManager->button->render(x - (int) ((float) clip->w * scale / 170), y*scale, clip, 0, nullptr, SDL_FLIP_NONE, scale / 85);
    else
        Game::textureManager->button->render(x, y*scale, clip, 0, nullptr, SDL_FLIP_NONE, scale);
    if(extended)
    {
        if (active)
        {
            comment[1]->draw();
            if (prev)
                this->change[0]->draw();
            if (next)
                this->change[1]->draw();
        }
        else
            comment[0]->draw();
    }
    if (active)
        text[1]->draw();
    else
        text[0]->draw();
}