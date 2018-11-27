#ifndef Letter_h
#define Letter_h

#include "Main.h"

class Letter
{
public:

    Letter( char character , std::string path , SDL_Color color , int size );

    char getCharacter();
    int getWidth();

    void draw( int x , int y );

private:

    char character;
    Texture* texture;

};

#endif
