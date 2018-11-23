#include "Main.h"

GameObject::GameObject(SDL_Renderer * ren, float x, float y, int width, int height , ObjectType type)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->renderer = ren;
    this->collider = new Collider(x,y, width, height);
    this->type = type;
}

Collider * GameObject::getCollider(){

    return collider;
}

void GameObject::destroy()
{

}

float GameObject::getX()
{
    return x;
}
float GameObject::getY()
{
    return y;
}
int GameObject::getW()
{
    return width;
}
int GameObject::getH()
{
    return height;
}
ObjectType GameObject::getType()
{
    return type;
}