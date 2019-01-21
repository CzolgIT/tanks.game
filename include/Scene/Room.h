#ifndef Room_h
#define Room_h

#include "Main.h"

class Room : public _Scene
{
public:

    explicit Room( std::string ipadress );
    void handleEvent() override;
    void draw() override;
    void reloadGUI() override;

    int selectedTank;

private:

    int selected;
    int maxSelected;
    std::vector<_Element*> elements;


    std::string ipadress;

    Sprite* mapSprite;
    TankSprite* sprite[6];
    float dir;

    Button * bt;
    Button * bt2;

};

#endif
