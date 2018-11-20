#include "Main.h"

Bullet::Bullet( SDL_Renderer* r , int x, int y, int dir)
        : GameObject(r, x, y, 36, 36)
{
    direction = dir;
    texture = new Texture( renderer , "assets/bullet.png" );
}

void Bullet::draw( int x0, int y0 )
{
    auto* bull = new SDL_Rect{0,0,36,36};

    texture->render(renderer , x0+x-(width*TANKSCALE/2) , y0+y-(height*TANKSCALE/2) , bull , direction-90 );
}

Collider Bullet::collider() {
    Collider col(x,y,width,height,direction);
    return col;
}

void Bullet::move( float timeStep )
{
    x -= (cos(direction *M_PI/180) * BULLETSPEED * timeStep);
    y -= (sin(direction *M_PI/180) * BULLETSPEED * timeStep);

    if( x < (int)((double)width/2) ||
        x > 2048 - (int)((double)width/2) ||
        y < (int)((double)height/2) ||
        y > 2048 - (int)((double)height/2)
        )
    {
        this->setToBeDestroyed();
    }

}
