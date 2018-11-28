#ifndef Button_h
#define Button_h

#include <GUIElement/TextStatic.h>
#include "Main.h"

class Button
{
public:

    Button( std::string name , float yy , std::string comm="" , float xx = -1 , bool center = true);
    void draw( bool active , bool prev=false , bool next=false );
    void setComment( std::string str );

private:

    TextStatic *text[2];
    TextStatic *comment[2];
    TextStatic *change[4];

    bool extended;
    float x,y;
    float scale;
    bool center;
    SDL_Rect* clip;

};

#endif