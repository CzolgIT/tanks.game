#include "Main.h"

Bullet::Bullet( SDL_Point position , int direction ) : _GameObject( position , {12,36} , direction , DYNAMIC )
{
    //direction = dir-90;
}

void Bullet::draw( int x0, int y0 )
{
    auto* bull = new SDL_Rect{0,0,dimensions.x,dimensions.y};
    Game::textureManager->bullet->draw(x0 + position.x - (dimensions.x * TANKSCALE / 2), y0 + position.y - (dimensions.y * TANKSCALE / 2), TANKSCALE ,bull,direction);
}

void Bullet::move()
{
    position.x -= (cos((direction+90) *M_PI/180) * BULLETSPEED * Game::stepTime );
    position.y -= (sin((direction+90) *M_PI/180) * BULLETSPEED * Game::stepTime );

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
