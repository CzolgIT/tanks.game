#include "Main.h"

Button::Button( std::string name , float x , float y , int flag , std::string subtext ) : _Element( name , x , y )
{
    this->flag = flag;
    this->active = false;

    if (!subtext.empty())
    {
        this->comment[0] = new TextStatic( subtext , x , y + 2 , 1 );
        this->comment[1] = new TextStatic( "<  " + subtext + "  >" , x , y + float(1.9) , 1.1 );
        this->text[0] = new TextStatic( name , x , y + float(0.5) , 1.3 );
        this->text[1] = new TextStatic( "+ " + name + " +" , x , y + float(0.4) , 1.4 );
    }
    else
    {
        this->comment[0] = nullptr;
        this->comment[1] = nullptr;
        this->text[0] = new TextStatic( name , x , y + float(0.9) , 1.6 );
        this->text[1] = new TextStatic( "+ " + name + " +" , x , y + float(0.8), 1.7 );
    }
}

void Button::draw()
{
    Game::textureManager->button->draw(x * xScale, y * yScale, yScale/85 );
    if(comment[0] != nullptr)
    {
        if (active)
            comment[1]->draw();
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

    if (comment[0] != nullptr)
    {
        this->comment[0]->updateScale();
        this->comment[1]->updateScale();
    }
    this->text[0]->updateScale();
    this->text[1]->updateScale();
}
void Button::setComment( std::string comment )
{
    if (this->comment[0] != nullptr)
    {
        delete(this->comment[0]);
        delete(this->comment[1]);
        this->comment[0] = new TextStatic( comment , x , y + 2 , 1 );
        this->comment[1] = new TextStatic( "<  " + comment + "  >" , x , y + float(1.9) , 1.1 );
    }
}


void Button::setActive(bool a) { this->active = a; }
int Button::getFlag() { return flag; }