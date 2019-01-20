#include "Main.h"

// type:
// BULLETEXPLODE = 0
// TANKDRIVE = 1
// TANKSHOOT = 2
// TANKEXPLODE = 3

Animation::Animation( AnimationType type , SDL_Point position , int rotation )
{
    switch(type) {
        case 0 :
            this->dimensions = {128,128};
            this->tex = Game::textureManager->bulletexplode;
            this->frames = 18;
            this->speed = 20;
            break;
        case 1 :
            this->dimensions = {128,128};
            this->tex = Game::textureManager->tankdrive;
            this->frames = 16;
            this->speed = 20;
            break;
        case 2 :
            this->dimensions = {128,128};
            this->tex = Game::textureManager->tankshoot;
            this->frames = 24;
            this->speed = 30;
            break;
        case 3 :
            this->dimensions = {720,512};
            this->tex = Game::textureManager->tankexplode;
            this->frames = 1; // ???
            this->speed = 10;
            break;
    }

    this->rotation = rotation;

    this->x = position.x;
    this->y = position.y;

    for( int i=0; i<frames; i++ )
        this->Sheet[i] = new Sprite( this->tex , { i*this->dimensions.x , 0 , this->dimensions.x , this->dimensions.y } , int(Game::configuration->getScale() * 0.8));
    this->frame = 0;
    this->todelete = false;
}

void Animation::draw(int x0, int y0)
{
    frame+= Game::windowManager->getStepTime() * speed ;

    if (int(frame)>=frames)
        this->todelete = true;
    else
        this->Sheet[int(frame)]->draw( { int(x0 + double(x)*Game::configuration->getScale() ) , int(y0 + double(y)*Game::configuration->getScale()) } ,rotation);
}

bool Animation::gettodelete()
{
    return todelete;
}