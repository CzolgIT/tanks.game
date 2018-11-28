#ifndef Menu_h
#define Menu_h

#include "Main.h"

class Menu : public _Scene
{
public:

    Menu();
    void handleEvents();
    void draw();

private:

    int selected;
    TextStatic* title[2];
    Button* button[4];
    void updateGUI();

};

#endif
