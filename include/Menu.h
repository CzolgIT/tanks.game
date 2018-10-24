#ifndef Menu_h
#define Menu_h

#include "Main.h"

class Menu
{
public:

    Menu( SDL_Renderer* r , Text* t );
    
    void loadTexts();
    int handleEvent( SDL_Event& e );
    void draw();
    
private:

    //Texture* TEX_Menu;
    //SDL_Rect clip1;
    
    SDL_Renderer* renderer;
    
    Text* text;
    
    int selected;
    
};

#endif /* Menu_h */
