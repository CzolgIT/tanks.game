#include <utility>

#include "Main.h"

Button::Button( std::string name, int yy, bool extended, std::string comm, int xx, bool center)
{
    this->extended = extended;
    this->scale = (int)((float)Game::configuration->getDisplayMode()->h/36);
    this->x = (xx == -1) ? Game::configuration->getDisplayMode()->w/2 : x;
    this->y = (int)((float)yy*scale);
    this->center = center;
    this->clip = new SDL_Rect{0,0,Game::textureManager->button->getWidth(),Game::textureManager->button->getHeight()};
    int add =0;

    if (extended)
    {
        add = (int)(scale/8);

        this->comment[0] = new TextStatic( comm , x , y + scale + scale/10+add*9 , scale , scale/10 );
        this->comment[1] = new TextStatic( comm , x , y + scale+add*9 , 1.1*scale , scale/10);

        this->change[0] = new TextStatic( "<" , x-scale*6 , y + scale + scale/10+add*9 , scale );
        this->change[1] = new TextStatic( "<" , x-scale*6-scale/10 , y + scale-scale/10+add*9 + scale/10 , scale);
        this->change[2] = new TextStatic( ">" , x+scale*6 , y + scale + scale/10+add*9 , scale );
        this->change[3] = new TextStatic( ">" , x+scale*6-scale/10 , y + scale-scale/10+add*9 + scale/10 , scale );
    }
    this->text[0] = new TextStatic( name , x , y + scale + scale/10-add*4 , 1.6*scale-add , scale/10 );
    this->text[1] = new TextStatic( "+ " + name + " +" , x , y + scale-add*4 , 1.7*scale-add , scale/10 );

}

void Button::setComment( std::string str )
{
    if (extended)
    {
        int add = (int)(scale/8);

        delete(this->comment[0]);
        delete(this->comment[1]);

        this->comment[0] = new TextStatic( str , x , y + scale + scale/10+add*9 , scale , scale/10 );
        this->comment[1] = new TextStatic( str , x , y + scale+add*9 , 1.1*scale  );
    }
}



void Button::draw(bool active , bool prev , bool next ) {
    if (center)
        Game::textureManager->button->render(x - (int) ((float) clip->w * scale / 170), y, clip, 0, nullptr, SDL_FLIP_NONE, scale / 85);
    else
        Game::textureManager->button->render(x, y, clip, 0, nullptr, SDL_FLIP_NONE, scale);

    if(extended)
    {
        if (active)
        {
            comment[1]->draw();
            if (prev)
            {
                this->change[0]->draw();
                this->change[1]->draw();
            }
            if (next)
            {
                this->change[2]->draw();
                this->change[3]->draw();
            }
        }
        else
            comment[0]->draw();
    }

    if (active)
        text[1]->draw();
    else
        text[0]->draw();


}