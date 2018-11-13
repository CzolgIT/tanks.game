#ifndef Room_h
#define Room_h

#include "Main.h"

class Room : public Scene
{
public:

    Room( SDL_Renderer* r , Text* t );
    void handleEvents();
    void draw();


private:
    TankSprite* sprite[4];
    float dir;

    int selected;
    int selectedTank;
};

#endif /* Room_h */
