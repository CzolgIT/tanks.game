#ifndef MainMenu_h
#define MainMenu_h

#include "Main.h"

class MainMenu : public _Scene
{
public:

    MainMenu();
    void handleEvents();
    void draw();

private:

    int selected;
    TextStatic* title[2];
    Button* button[4];
    void updateGUI();

};

#endif
