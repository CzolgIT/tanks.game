#include <utility>

#include "Main.h"

_Element::_Element( std::string name , float x , float y )
{
    this->name = std::move(name);
    this->x = x;
    this->y = y;

    this->xScale = float(Game::configuration->getDisplayMode()->w)/64;
    this->yScale = float(Game::configuration->getDisplayMode()->h)/36;
}
