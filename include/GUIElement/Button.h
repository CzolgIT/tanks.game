#ifndef Button_h
#define Button_h

#include <GUIElement/TextStatic.h>
#include "Main.h"

class Button : public _Element
{
public:

    Button( std::string name , float x , float y , int flag , std::string comm="" );

    void draw();
    void updateScale();

    int getFlag();

    void setActive(bool a);
    void setLeftArrow(bool l);
    void setRightArrow(bool r);

private:

    int flag;

    TextStatic *text[2];
    TextStatic *comment[2];
    TextStatic *change[4];

    bool active;
    bool leftArrow;
    bool rightArrow;

};

#endif