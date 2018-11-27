#ifndef Button_h
#define Button_h

#include "Main.h"

class Button
{
public:

    Button( std::string name , int x , int y , float scale , bool center);
    void draw( bool active );

private:

    std::string name;
    int x,y;
    float scale;
    bool center;
    SDL_Rect* clip;

};

#endif