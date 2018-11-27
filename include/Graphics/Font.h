#ifndef Font_h
#define Font_h

#include "Main.h"

class Font
{
public:

    Font( std::string path , int size , SDL_Color color );

    std::string getPath();
    int getSize();
    int getR();
    int getG();
    int getB();

    void draw( std::string str, int x, int y, bool center);

private:

    std::string path;
    int size;
    SDL_Color color;
    std::vector<Letter*> letters;

};

#endif
