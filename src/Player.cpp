#include "Main.h"

Player::Player( SDL_Renderer* r , Texture* t , int x , int y )
{
    this->x = x;
    this->y = y;

    width=100;
    height=100;

    direction=90;
    towerDirection=90;

    moveSpeed = 0;
    directionSpeed = 0;
    towerSpeed = 0;

    renderer = r;
    texture = t;

    spriteTrackLeft = new Sprite( renderer , texture , 512+96+122+122 , 0 , 33 , 158 , 66 , 80 );
    spriteTrackRight = new Sprite( renderer , texture , 512+96+122+122 , 0 , 33 , 158 , -33 , 80 );
    spriteBody = new Sprite( renderer , texture , 512+96 , 0 , 122 , 171 , 61 , 84 );
    spriteTower = new Sprite( renderer , texture , 512 , 0 , 96 , 128 , 48 , 64 );
    spriteBarrel = new Sprite( renderer , texture , 512+96 , 171+171 , 54 , 131 , 27 , 105 );
}

void Player::handleEvent( SDL_Event& e )
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: moveSpeed -= TANKMAXSPEED; break;
            case SDLK_DOWN: moveSpeed += TANKMAXSPEED; break;
            case SDLK_LEFT: directionSpeed -= TANKMAXDIRECTIONSPEED; break;
            case SDLK_RIGHT: directionSpeed += TANKMAXDIRECTIONSPEED; break;
            case SDLK_z: towerSpeed -= TANKMAXDIRECTIONSPEED; break;
            case SDLK_x: towerSpeed += TANKMAXDIRECTIONSPEED; break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: moveSpeed += TANKMAXSPEED; break;
            case SDLK_DOWN: moveSpeed -= TANKMAXSPEED; break;
            case SDLK_LEFT: directionSpeed += TANKMAXDIRECTIONSPEED; break;
            case SDLK_RIGHT: directionSpeed -= TANKMAXDIRECTIONSPEED; break;
            case SDLK_z: towerSpeed += TANKMAXDIRECTIONSPEED; break;
            case SDLK_x: towerSpeed -= TANKMAXDIRECTIONSPEED; break;
        }
    }
}

void Player::move( float timeStep )
{
    // move forward and back
    x += (int)(cos(direction *M_PI/180) * moveSpeed * timeStep);
    y += (int)(sin(direction *M_PI/180) * moveSpeed * timeStep);

    // rotate tank and tower
    direction += directionSpeed * timeStep ;
    towerDirection += directionSpeed * timeStep ;
    towerDirection += towerSpeed * timeStep ;

    // Wall limits
    if( x < 0 )
    {
        x = 0;
    }
    else if( x > SCREEN_WIDTH - width )
    {
        x = SCREEN_WIDTH - width;
    }

    if( y < 0 )
    {
        y = 0;
    }
    else if( y > SCREEN_HEIGHT - height )
    {
        y = SCREEN_HEIGHT - height;
    }
}

void Player::draw()
{
    spriteTrackLeft->draw( x , y+25 , direction);
    spriteTrackRight->draw( x+99, y+25 , direction);
    spriteBody->draw( x+5, y+21 , direction);
    spriteTower->draw( x+18, y+41 , towerDirection);
    spriteBarrel->draw( x+39, y , towerDirection);
}
