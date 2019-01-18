#ifndef Room_h
#define Room_h

#include "Main.h"

class Room : public _Scene
{
public:

    explicit Room( std::string ipadress );
    void handleEvent() override;
    void draw() override;

    int selectedTank;

private:

    std::string ipadress;

    TankSprite* sprite[6];
    float dir;

    Button * bt;
    Button * bt2;

};

#endif
