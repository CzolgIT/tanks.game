#ifndef Room_h
#define Room_h

#include "Main.h"

class Room
{
public:
    
    Room( SDL_Renderer* r , Text* t );
    int handleEvent( SDL_Event& e );
    void draw();
    
private:

    TankSprite* sprite[4];
    float dir;
    
    SDL_Renderer* renderer;
    Text* text;

    int selected;
    int selectedTank;
};

#endif /* Room_h */
