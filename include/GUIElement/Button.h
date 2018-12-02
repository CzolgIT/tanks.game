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
    void setComment( std::string comment );

    int getFlag();
    void setActive(bool a);

private:

    int flag;
    TextStatic *text[2];
    TextStatic *comment[2];
    bool active;

};

#endif