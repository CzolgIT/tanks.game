#ifndef Button_h
#define Button_h

#include <Text/TextStatic.h>
#include "Main.h"

class Button
{
public:

    Button( std::string name , int x , int y , float scale , bool center);
    void draw( bool active );

private:

    TextStatic *textw;
    TextStatic *textb;
    TextStatic *textActivew;
    TextStatic *textActiveb;
    std::string name;
    int x,y;
    float scale;
    bool center;
    SDL_Rect* clip;

};

#endif