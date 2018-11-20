#include "Main.h"

Player::Player( SDL_Renderer* r , Text* t , float x , float y , int color ) : GameObject(r,x,y,170,130)
{
    text = t;

    direction=90;
    towerDirection=90;

    moveSpeed = 0;
    directionSpeed = 0;
    towerSpeed = 0;

    sprite = new TankSprite( renderer , color );

}

Collider Player::collider(){

    Collider col(x,y,width,height, direction);
    return col;
}

void Player::handleEvent( SDL_Event& e )
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            //case SDLK_UP: moveSpeed += TANKMAXSPEED; break;
            //case SDLK_DOWN: moveSpeed -= TANKMAXSPEED; break;
            //case SDLK_LEFT: directionSpeed -= TANKMAXDIR; break;
            //case SDLK_RIGHT: directionSpeed += TANKMAXDIR; break;
            //case SDLK_z: towerSpeed -= TANKMAXDIR; break;
            //case SDLK_x: towerSpeed += TANKMAXDIR; break;
        }
    }

    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            //case SDLK_UP: moveSpeed -= TANKMAXSPEED; break;
            //case SDLK_DOWN: moveSpeed += TANKMAXSPEED; break;
            //case SDLK_LEFT: directionSpeed += TANKMAXDIR; break;
            //case SDLK_RIGHT: directionSpeed -= TANKMAXDIR; break;
            //case SDLK_z: towerSpeed += TANKMAXDIR; break;
            //case SDLK_x: towerSpeed -= TANKMAXDIR; break;
        }
    }
}

void Player::move( float timeStep )
{

    moveSpeed = accelerate( SDL_SCANCODE_UP , moveSpeed , 0 , TANKMAXSPEED , timeStep );
    moveSpeed = accelerate( SDL_SCANCODE_DOWN , moveSpeed , 0 , -TANKMAXSPEED , timeStep );
    directionSpeed = accelerate( SDL_SCANCODE_RIGHT , directionSpeed , 0 , TANKMAXDIR , timeStep );
    directionSpeed = accelerate( SDL_SCANCODE_LEFT , directionSpeed , 0 , -TANKMAXDIR , timeStep );
    towerSpeed = accelerate( SDL_SCANCODE_X , towerSpeed , 0 , TANKMAXDIR , timeStep );
    towerSpeed = accelerate( SDL_SCANCODE_Z , towerSpeed , 0 , -TANKMAXDIR , timeStep );

    // move forward and back
    x -= (cos(iDirection *M_PI/180) * moveSpeed * timeStep);
    y -= (sin(iDirection *M_PI/180) * moveSpeed * timeStep);

    // rotate tank and tower
    direction += directionSpeed * timeStep ;
    towerDirection += directionSpeed * timeStep + towerSpeed * timeStep;

    if ( direction > 360 ) direction -= 360;
    if ( towerDirection > 360 ) towerDirection -= 360;

    if ( direction < 0 ) direction += 360;
    if ( towerDirection < 0 ) towerDirection += 360;

    // dzięki temu kąt obrotu będzie można zapisać jako liczbę
    // od 0 do 180 i zmieści się w jednym bajcie
    iDirection = (int)round(direction/2)*2;
    iTowerDirection = (int)round(towerDirection/2)*2;

    //std::cout << iDirection << "  " << iTowerDirection << "\n";

    // Wall limits
    if( x < width/2 )
    {
        x = width/2 ;
    }
    else if( x > 2048 - width/2 )
    {
        x = 2048 - width/2;
    }

    if( y < height/2 )
    {
        y = height/2;
    }
    else if( y > 2048 - height/2 )
    {
        y = 2048 - height/2;
    }

}

void Player::draw( int x0 , int y0 )
{
    Collider col = collider();
    for (int i = 0; i < 4; i ++){
        if (i != 3)
            SDL_RenderDrawLine( renderer,x0 + col.points[i].x ,y0+ col.points[i].y ,x0+ col.points[i+1].x, y0+col.points[i+1].y );
        else
            SDL_RenderDrawLine( renderer,x0 + col.points[i].x , y0+col.points[i].y ,x0 + col.points[0].x, y0+col.points[0].y );
    }

    sprite->draw( SCR_W/2 , SCR_H/2 , iDirection , iTowerDirection , moveSpeed );

    text->draw( "x: " + std::to_string( x ) ,  100 , 500 );
    text->draw( "y: " + std::to_string( y ) ,  100 , 530 );
    text->draw( "sp: " + std::to_string( moveSpeed ) ,  100 , 560 );


}

int Player::getTowDir()
{
    return iTowerDirection;
}

float Player::accelerate( int scanCode , float what , float from , float to , float timeStep )
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

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
