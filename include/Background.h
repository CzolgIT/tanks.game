#ifndef Background_h
#define Background_h

#include "Main.h"

class Background
{
public:
    Background( SDL_Renderer* r );
    //void loadFromTexture( Texture* t , int x , int y , int w , int h );
    void draw( int x , int y ); // rysuje tylko tyle obrazków ile potrzeba na okno gry
    
private:
    SDL_Renderer* renderer;
    Texture* texture;
    SDL_Rect clip;
    int width , height;
};

#endif /* Background_h */
