#include "Main.h"

Bullet::Bullet( SDL_Point position , int direction, int id ) : _GameObject( position , {36,12} , direction , DYNAMIC )
{
    //this->direction = direction;
    this->floatX = position.x;
    this->floatY = position.y;
    this->id = id;

    sprite = new Sprite(Game::textureManager->bullet,{0,0,36,36},Game::configuration->getScale()/2);
}

void Bullet::draw( int x0, int y0 )
{
    sprite->draw({ int(x0 + double(position.x) * Game::configuration->getScale() ) , int(y0 + double(position.y) * Game::configuration->getScale() ) },direction);
}

int Bullet::getId() {
    return id;
}

void Bullet::move()
{

    this->floatX += (cos(double(direction) *M_PI/180) * BULLETSPEED * Game::windowManager->getStepTime() );
    this->floatY += (sin(double(direction) *M_PI/180) * BULLETSPEED * Game::windowManager->getStepTime() );


    position.x = int(floatX);
    position.y = int(floatY);

    if ( floatX< 0 || floatX > 64*64 || floatY<0 || floatY> 64*64 )
        this->setToBeDestroyed();

}



void Bullet::reloadGUI()
{
    delete sprite;
    sprite = nullptr;
    sprite = new Sprite(Game::textureManager->bullet,{0,0,36,36},Game::configuration->getScale()/2);
}