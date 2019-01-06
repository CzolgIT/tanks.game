#include "Main.h"

Player::Player( SDL_Point position , int color ) : _GameObject( position , { (int)((double)170*TANKSCALE),(int)((double)130*TANKSCALE) }  , 0 , DYNAMIC )
{
    directionFloat=0;
    towerDirection=0;

    moveSpeed = 0;
    directionSpeed = 0;
    towerSpeed = 0;

    sprite = new TankSprite( color );
    collider = new Collider( position , dimensions , direction );

    blocked = {0,0};

    xFloat = position.x;
    yFloat = position.y;
}

void Player::handleEvent( SDL_Event& e )
{
    // not used anymore
}

void Player::PushOut(Vector2D vec)
{
    blocked.x -= vec.x;
    blocked.y -= vec.y;
}

void Player::move()
{
    float timeStep = Game::stepTime;

    // acceleration
    moveSpeed = accelerate( SDL_SCANCODE_UP , moveSpeed , 0 , TANKMAXSPEED , timeStep );
    moveSpeed = accelerate( SDL_SCANCODE_DOWN , moveSpeed , 0 , -TANKMAXSPEED , timeStep );
    directionSpeed = accelerate( SDL_SCANCODE_RIGHT , directionSpeed , 0 , TANKMAXDIR , timeStep );
    directionSpeed = accelerate( SDL_SCANCODE_LEFT , directionSpeed , 0 , -TANKMAXDIR , timeStep );
    towerSpeed = accelerate( SDL_SCANCODE_X , towerSpeed , 0 , TANKMAXDIR , timeStep );
    towerSpeed = accelerate( SDL_SCANCODE_Z , towerSpeed , 0 , -TANKMAXDIR , timeStep );


    double xm = cos((direction) *M_PI/180) * moveSpeed * timeStep;
    double ym = sin((direction) *M_PI/180) * moveSpeed * timeStep;


    if (blocked.x ==0 ) xFloat += xm;
    if (blocked.x>0.1 || blocked.x<-0.1) xFloat += -blocked.x;

    if (blocked.y == 0 ) yFloat += ym;
    if (blocked.y>0.1 || blocked.y<-0.1) yFloat += -blocked.y;

    position.x = int(xFloat);
    position.y = int(yFloat);

    // rotate tank and tower
    directionFloat += directionSpeed * timeStep ;
    towerDirection += directionSpeed * timeStep + towerSpeed * timeStep;

    if ( directionFloat > 360 ) directionFloat -= 360;
    if ( towerDirection > 360 ) towerDirection -= 360;

    if ( directionFloat < 0 ) directionFloat += 360;
    if ( towerDirection < 0 ) towerDirection += 360;

    // dzięki temu kąt obrotu będzie można zapisać jako liczbę
    // od 0 do 180 i zmieści się w jednym bajcie
    direction = (int)round(directionFloat/2)*2;
    iTowerDirection = (int)round(towerDirection/2)*2;

    //std::cout << iDirection << "  " << iTowerDirection << "\n";

    // Wall limits
    if( position.x < (int)((double)dimensions.x/2) )
    {
        position.x = (int)((double)dimensions.x/2) ;
    }
    else if( position.x > 2048 - (int)((double)dimensions.x/2) )
    {
        position.x = 2048 - (int)((double)dimensions.x/2);
    }

    if( position.y < (int)((double)dimensions.y/2) )
    {
        position.y = (int)((double)dimensions.y/2);
    }
    else if( position.y > 2048 - (int)((double)dimensions.y/2) )
    {
        position.y = 2048 - (int)((double)dimensions.y/2);
    }

    collider->update( position , dimensions , direction );

}

void Player::draw( int x0 , int y0 )
{
    /*
    for (int i = 0; i < 4; i ++){
        if (i != 3)
            SDL_RenderDrawLine( renderer,x0 + collider->points[i].x ,y0+ collider->points[i].y ,x0+ collider->points[i+1].x, y0+collider->points[i+1].y );
        else
            SDL_RenderDrawLine( renderer,x0 + collider->points[i].x , y0+collider->points[i].y ,x0 + collider->points[0].x, y0+collider->points[0].y );
    }
    */

    sprite->draw( { Game::configuration->getDisplayMode()->w/2 , Game::configuration->getDisplayMode()->h/2 } , direction , iTowerDirection , (int)moveSpeed );

    Game::textManager->draw( "x: " + std::to_string( position.x ) ,  150 , 500 );
    Game::textManager->draw( "y: " + std::to_string( position.y ) ,  150 , 520 );
    Game::textManager->draw( "sp: " + std::to_string( moveSpeed ) ,  150 , 540 );
    Game::textManager->draw( "dir: " + std::to_string( direction ) ,  150 , 560 );

    Game::textManager->draw( "xblock: " + std::to_string( blocked.x ) ,  550 , 500 );
    Game::textManager->draw( "yblock: " + std::to_string( blocked.y ) ,  550 , 530 );


    if (blocked.x != 0 || blocked.y != 0)
        std::cout << blocked.x << "   " << blocked.y << "\n";

    blocked.x = 0;
    blocked.y = 0;

}

int Player::getTowDir()
{
    return iTowerDirection;
}

int Player::getDir()
{
    return direction;
}

float Player::accelerate( int scanCode , float what , float from , float to , float timeStep )
{
    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    if (state[scanCode])
    {
        if ( from < to ? what < to : what > to )
        {
            what += to * timeStep * TANKACCELERATION ;
            if ( from < to ? what > to : what < to ) what = to;
        }
    }
    else
    {
        if ( from < to ? what > from : what < from )
        {
            what -= to * timeStep * TANKACCELERATION;
            if ( from < to ? what < from : what > from ) what = from;
        }
    }
    return what;
}

SDL_Point Player::shootPosition()
{
    SDL_Point punkt;
    punkt.x = (int)(position.x+(cos(iTowerDirection *M_PI/180) * -50));
    punkt.y = (int)(position.y+(sin(iTowerDirection *M_PI/180) * -50));
    return punkt;
}
SDL_Point Player::smokePosition()
{
    SDL_Point punkt;
    int dir = direction;
    punkt.x = (int)(position.x+(cos(direction *M_PI/180) * -50));
    punkt.y = (int)(position.y+(sin(direction *M_PI/180) * -50));
    return punkt;
}
