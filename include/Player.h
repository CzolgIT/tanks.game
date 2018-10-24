#ifndef Player_h
#define Player_h

#include "Main.h"

class Player: public GameObject
{
public:

    Player( SDL_Renderer* r , float x , float y ) ;
    void loadSprites();
    void handleEvent( SDL_Event& e );
    void move( float timeStep );
    virtual void draw();

private:
    
    // aktualne predkosci
    int moveSpeed , directionSpeed , towerSpeed;
    
    // aktualne pozycje obrotu
    float direction , towerDirection;
    
    // aktualne pozycje obrotu do wyswietlania, poruszania w kierunku i przesylania do serwera
    int iDirection , iTowerDirection;
    
    // maksymalne predkosci
    int tankMaxSpeed , tankMaxSpeedDir;

    Sprite* spriteTrackLeft;
    Sprite* spriteTrackRight;
    Sprite* spriteBody;
    Sprite* spriteTower;
    Sprite* spriteBarrel;

};

#endif /* Player_h */
