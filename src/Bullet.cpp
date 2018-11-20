#include "Main.h"

Bullet::Bullet( SDL_Renderer* r , int x, int y, int dir)
        : GameObject(r, x, y, 36, 36)
{
    direction = dir;
    texture = new Texture( renderer , "assets/bullet.png" );
}

void Bullet::draw( int x0, int y0 )
{
    SDL_Rect* bull = new SDL_Rect{0,0,36,36};

    texture->render(renderer , x0+x-(width*TANKSCALE/2) , y0+y-(height*TANKSCALE/2) , bull , direction-90 );
}

void Bullet::move( float timeStep )
{
x -= (cos(direction *M_PI/180) * BULLETSPEED * timeStep);
y -= (sin(direction *M_PI/180) * BULLETSPEED * timeStep);
}

