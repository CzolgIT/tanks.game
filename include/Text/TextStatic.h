#ifndef TextStatic_h
#define TextStatic_h

#include "Main.h"

class TextStatic
{
public:

    TextStatic( std::string str , int x , int y , int size , SDL_Color color);
    void draw();

private:

    Texture* texture;
    int x,y;

};

#endif
