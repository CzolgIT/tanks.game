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
    
    // znaki od 32 do 126
    // rozmiary (domyslnie tylko 16)
    Texture* letter[128][128];
    
    int size;
    void newSize( int s );
    SDL_Color color;
    bool align;
    
    
    
};




#endif /* Text_h */
