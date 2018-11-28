#ifndef Button_h
#define Button_h

#include <GUIElement/TextStatic.h>
#include "Main.h"

class Button : public _Element
{
public:

    Button( std::string name , float x , float y , std::string comm="" );

    void draw( bool active , bool prev=false , bool next=false );
    void updateScale();
    //void setComment( std::string str );

private:

    std::string subtext;


    TextStatic *text[2];
    TextStatic *comment[2];
    TextStatic *change[4];

    bool extended;
    float scale;
    SDL_Rect* clip;

};

#endif