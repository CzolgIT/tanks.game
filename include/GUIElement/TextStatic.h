#ifndef TextStatic_h
#define TextStatic_h

#include "Main.h"

class TextStatic
{
public:

    TextStatic( std::string str , float y , float size , float shadow=-1 , float x=-1 );
    void draw();

private:

    Texture* black;
    Texture* white;
    int shadow;
    int x,y;

};

#endif
