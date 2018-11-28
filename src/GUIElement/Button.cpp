#include "Main.h"

Button::Button( std::string name , float x , float y , std::string subtext ) : _Element( name , x , y )
{
    this->clip = new SDL_Rect{0,0,Game::textureManager->button->getWidth(),Game::textureManager->button->getHeight()};
    float add =0;

    if (!subtext.empty())
    {
        add = (0.125);
        this->comment[0] = new TextStatic( subtext , x , y + 2 , 1 );
        this->comment[1] = new TextStatic( subtext , x , y + 1.9 , 1.1 );
        this->change[0] = new TextStatic( "<" , x-6 , y + 1.9 , 1 );
        this->change[1] = new TextStatic( ">" , x+6 , y + 1.9 , 1 );
    }
    this->text[0] = new TextStatic( name , x , y + 0.9 -add*4 , 1.6-add );
    this->text[1] = new TextStatic( "+ " + name + " +" , x , y + 0.8-add*4 , 1.7-add );

}

void Button::draw( bool active , bool prev , bool next )
{
    Game::textureManager->button->draw(x * xScale, y * yScale, yScale/85 );

    if(!subtext.empty())
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
void Button::updateScale()
{
    this->xScale = float(Game::configuration->getDisplayMode()->w)/64;
    this->yScale = float(Game::configuration->getDisplayMode()->h)/36;
}
