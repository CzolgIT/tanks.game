#ifndef Background_h
#define Background_h

#include "Main.h"

class Background
{
public:

    Background();
    void draw( int x , int y );
    
private:

    //Texture* texture;
    SDL_Rect clip;
    int width , height;

    SDL_Rect clip2;
    
};

#endif /* Background_h */
