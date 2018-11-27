#ifndef Button_h
#define Button_h

#include <Text/TextStatic.h>
#include "Main.h"

class Button
{
public:

    Button( std::string name , int yy , bool extended=false , std::string comm="" , int xx = -1 , bool center = true);
    void draw( bool active , bool prev=false , bool next=false );
    void setComment( std::string str );

private:

    TextStatic *text[2];
    TextStatic *comment[2];
    TextStatic *change[4];

    bool extended;
    int x,y;
    float scale;
    bool center;
    SDL_Rect* clip;

};

#endif