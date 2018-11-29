#include "Main.h"

Button::Button( std::string name , float x , float y , int flag , std::string subtext ) : _Element( name , x , y )
{
    this->flag = flag;

    this->active = false;
    this->leftArrow = false;
    this->rightArrow = false;

    if (!subtext.empty())
    {
        this->comment[0] = new TextStatic( subtext , x , y + 2 , 1 );
        this->comment[1] = new TextStatic( subtext , x , y + float(1.9) , 1.1 );
        this->change[0] = new TextStatic( "<" , x-6 , y + float(1.9) , 1 );
        this->change[1] = new TextStatic( ">" , x+6 , y + float(1.9) , 1 );

        this->text[0] = new TextStatic( name , x , y + float(0.5) , 1.3 );
        this->text[1] = new TextStatic( "+ " + name + " +" , x , y + float(0.4) , 1.4 );
    }
    else
    {
        this->comment[0] = nullptr;
        this->comment[1] = nullptr;
        this->change[0] = nullptr;
        this->change[1] = nullptr;
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
        {
            comment[1]->draw();
            if (leftArrow)
                this->change[0]->draw();
            if (rightArrow)
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

    if (comment[0] != nullptr)
    {
        this->comment[0]->updateScale();
        this->comment[1]->updateScale();
        this->change[0]->updateScale();
        this->change[1]->updateScale();
    }
    this->text[0]->updateScale();
    this->text[1]->updateScale();
}

void Button::setActive(bool a) { this->active = a; }
void Button::setLeftArrow(bool l) { this->leftArrow = l; }
void Button::setRightArrow(bool r) { this->rightArrow = r; }

int Button::getFlag() { return flag; }