#ifndef Room_h
#define Room_h

#include "Main.h"

class Room : public _Scene
{
public:

    Room();
    void handleEvents();
    void draw();

private:

    NetManager* netManager;
    TankSprite* sprite[4];
    float dir;
    int selectedTank;

};

#endif
