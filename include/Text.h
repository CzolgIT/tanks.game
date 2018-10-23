#ifndef Text_h
#define Text_h

#include "Main.h"

class Text
{
public:

    Text( SDL_Renderer* r , std::string f );
    
    void draw( std::string str , int x , int y );
    
    void setSize( int s );
    void setColor( SDL_Color c );
    void setAlignment( bool a );
    
private:

    SDL_Renderer* renderer;
    std::string fontPath;
    
    int size;
    void newSize();
    SDL_Color color;
    bool align;
    
    
    
};




#endif /* Text_h */
