#ifndef Player_h
#define Player_h

#include "Main.h"

class Player: public GameObject
{
public:

    Player( SDL_Renderer* r , Texture* texture , float x , float y ) ;

    void loadSprites();

    void handleEvent( SDL_Event& e );

    void move( float timeStep );

    virtual void draw();

    int direction,towerDirection;
    float moveSpeed;

private:


    int tankMaxSpeed;
    int tankMaxSpeedDir;

    Sprite* spriteTrackLeft;
    Sprite* spriteTrackRight;
    Sprite* spriteBody;
    Sprite* spriteTower;
    Sprite* spriteBarrel;

    float directionSpeed;
    float towerSpeed;
};

#endif /* Player_h */
