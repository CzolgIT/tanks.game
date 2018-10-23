#ifndef Text_h
#define Text_h

#include "Main.h"

class Text
{
public:

    Text( SDL_Renderer* r , std::string newText , TTF_Font* font );
    void draw( int x , int y , bool center = true);
    
private:
    
    SDL_Renderer* renderer;
    
    TTF_Font* font[20];
    SDL_Color textColor;
    Texture* texture;
    std::string textString;
    
};




#endif /* Text_h */
