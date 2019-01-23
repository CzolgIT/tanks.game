#include "Main.h"

_GameObject::_GameObject( SDL_Point position , SDL_Point dimensions , int direction)
{
    this->position = position;
    this->dimensions = dimensions;
    this->direction = direction;

    this->toDestroy = false;
}


SDL_Point _GameObject::getPosition()
{
    return this->position;
}

int _GameObject::getX()
{
    return this->position.x;
}

int _GameObject::getY()
{
    return this->position.y;
}

SDL_Point _GameObject::getDimensions()
{
    return this->dimensions;
}

int _GameObject::getW()
{
    return this->dimensions.x;
}

int _GameObject::getH()
{
    return this->dimensions.y;
}
