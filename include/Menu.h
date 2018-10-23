#ifndef Menu_h
#define Menu_h

#include "Main.h"

class Menu
{
public:

    Menu( SDL_Renderer* r );
    
    void loadTexts();
    void draw();
    
private:

    Texture* TEX_Menu;
    
    SDL_Renderer* renderer;
    
    SDL_Rect clip1;
    
    TTF_Font* font;
    
    int selected;
    
    Text* text_game;
    Text* text_new;
    Text* text_join;
    Text* text_settings;
    Text* text_exit;

};

#endif /* Menu_h */
