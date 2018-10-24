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

private:
    
    int moveSpeed , directionSpeed , towerSpeed; // aktualne predkosci
    float direction , towerDirection; // aktualne pozycje obrotu
    int tankMaxSpeed , tankMaxSpeedDir; // maksymalne predkosci

    Sprite* spriteTrackLeft;
    Sprite* spriteTrackRight;
    Sprite* spriteBody;
    Sprite* spriteTower;
    Sprite* spriteBarrel;

};

#endif /* Player_h */
