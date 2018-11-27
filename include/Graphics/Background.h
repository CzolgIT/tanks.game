#ifndef Background_h
#define Background_h

#include "Main.h"

class Background
{
public:

    Background();
    void draw( int x , int y );
    
private:

    Texture* texture;
    SDL_Rect clip;
    int width , height;
    
};

#endif /* Background_h */
