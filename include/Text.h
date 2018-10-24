#ifndef Text_h
#define Text_h

#include "Main.h"

class Text
{
public:

    Text( SDL_Renderer* r , std::string f );
    ~Text();
    
    void draw( std::string str , int x , int y );
    
    void setSize( int s );
    void setColor( SDL_Color c );
    //void setAlignment( bool a ); // TODO: alignment
    
private:

    SDL_Renderer* renderer;
    std::string fontPath;
    
    // znaki od 32 do 126
    // rozmiary (domyslnie tylko 16)
    // kolor R G B
    Texture* letter[128][128][256][256][256];
    
    int size;
    void newCollection();
    SDL_Color color;
    //bool align; // TODO: alignment
    
    TTF_Font* font;
    
};




#endif /* Text_h */
