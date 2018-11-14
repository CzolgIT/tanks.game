#ifndef Menu_h
#define Menu_h

#include "Main.h"

class Menu : public Scene
{
public:

    Menu( SDL_Renderer* r , Text* t );
    void loadTexts();
    void handleEvents();
    void draw();
private:
    int selected;

};

#endif /* Menu_h */
