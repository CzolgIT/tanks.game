#include "Main.h"

PowerUp::PowerUp(int id , SDL_Point position, int type) : _GameObject( position , {64,64} , 0 , STATIC )
{
    this->id = id;
    this->type = type;

    sprite = new Sprite(Game::textureManager->powerups,{160*type,0,160,160},0.4*Game::configuration->getScale());
}

void PowerUp::draw(int x0 , int y0)
{
    sprite->draw({ int(x0 + double(position.x) * Game::configuration->getScale() ) , int(y0 + double(position.y) * Game::configuration->getScale() ) },0);
}

void PowerUp::reloadGUI()
{
    delete sprite;
    sprite = nullptr;
    sprite = new Sprite(Game::textureManager->powerups,{160*type,0,160,160},float(0.4*Game::configuration->getScale()));
}