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
    sprite->draw({ x0 + position.x , y0 + position.y },direction);
}

int Bullet::getId() {
    return id;
}

void Bullet::move()
{

    this->floatX += (cos(double(direction) *M_PI/180) * BULLETSPEED * Game::configuration->getScale() * Game::windowManager->getStepTime() );
    this->floatY += (sin(double(direction) *M_PI/180) * BULLETSPEED * Game::configuration->getScale() * Game::windowManager->getStepTime() );


    position.x = int(floatX);
    position.y = int(floatY);



    if( position.x < 0 || position.x > 4096 || position.y < 0 || position.y > 4096 )
    {
        this->setToBeDestroyed();
    }

    //collider->update( position , dimensions , direction );

}

void Bullet::destroy()
{

}