#ifndef Player_h
#define Player_h

#include "Main.h"

class Player: public GameObject
{
public:

    Player( SDL_Renderer* r , Texture* t , float x , float y );

    void loadSprites();

    void handleEvent( SDL_Event& e );

    void move( float timeStep );

    virtual void draw();

    float direction,towerDirection;
    float moveSpeed;

private:

    Sprite* spriteTrackLeft;
    Sprite* spriteTrackRight;
    Sprite* spriteBody;
    Sprite* spriteTower;
    Sprite* spriteBarrel;

    float directionSpeed;
    float towerSpeed;
};

#endif /* Player_h */
