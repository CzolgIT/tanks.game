#ifndef Player_h
#define Player_h

#include "Main.h"

class Player: public GameObject
{
public:

    Player( SDL_Renderer* r , Text* t , float x , float y , int color ) ;
    void handleEvent( SDL_Event& e );
    void move( float timeStep );
    void draw( int x0 , int y0 );
    Collider collider();
    int getTowDir();

private:

    float accelerate( int scanCode , float what , float from , float to , float timeStep );

    // wskaznik do rysownika tekstow
    Text* text;

    // aktualne predkosci
    float moveSpeed , directionSpeed , towerSpeed;

    // aktualne pozycje obrotu
    float direction , towerDirection;

    // aktualne pozycje obrotu do wyswietlania, poruszania w kierunku i przesylania do serwera
    int iDirection , iTowerDirection;

    TankSprite* sprite;


};

#endif /* Player_h */
