#ifndef Room_h
#define Room_h

#include "Main.h"

class Room : public Scene
{
public:

    Room( SDL_Renderer* r , Text* t , Configuration* c , NetManager* net);
    void handleEvents( float frameTime );
    void draw( float frameTime );

private:

    NetManager* netManager;
    TankSprite* sprite[4];
    float dir;
    int selectedTank;

};

#endif
