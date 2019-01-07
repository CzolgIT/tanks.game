#include "Main.h"

Bullet::Bullet( SDL_Point position , int direction ) : _GameObject( position , {36,12} , direction , DYNAMIC )
{
    //this->direction = direction;
    this->floatX = position.x;
    this->floatY = position.y;
}

void Bullet::draw( int x0, int y0 )
{
    auto* bull = new SDL_Rect{0,0,dimensions.x,dimensions.y};
    Game::textureManager->bullet->draw(x0 + position.x , y0 + position.y , TANKSCALE , bull , direction );
}

void Bullet::move()
{

    this->floatX += (cos(double(direction) *M_PI/180) * BULLETSPEED * Game::windowManager->getStepTime() );
    this->floatY += (sin(double(direction) *M_PI/180) * BULLETSPEED * Game::windowManager->getStepTime() );


    position.x = int(floatX);
    position.y = int(floatY);



    if( position.x < (int)((double)dimensions.x/2) ||
            position.x > 2048 - (int)((double)dimensions.x/2) ||
            position.y < (int)((double)dimensions.y/2) ||
            position.y > 2048 - (int)((double)dimensions.y/2)
        )
    {
        this->setToBeDestroyed();
    }

    collider->update( position , dimensions , direction );

}

void Bullet::destroy()
{

}