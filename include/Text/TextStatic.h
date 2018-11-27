#ifndef TextStatic_h
#define TextStatic_h

#include "Main.h"

class TextStatic
{
public:

    TextStatic( std::string str , int x , int y , int size , int shadow=0 );
    void draw();

private:

    Texture* black;
    Texture* white;
    int shadow;
    int x,y;

};

#endif
