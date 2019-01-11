#ifndef Room_h
#define Room_h

#include "Main.h"

class Room : public _Scene
{
public:

    Room( std::string ipadress );
    void handleEvents();
    void draw();
    int selectedTank;
private:

    std::string ipadress;

    NetManager* netManager;
    TankSprite* sprite[6];
    float dir;

    Button * bt;
    Button * bt2;

};

#endif
