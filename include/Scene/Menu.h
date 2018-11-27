#ifndef Menu_h
#define Menu_h

#include "Main.h"

class Menu : public Scene
{
public:

    Menu();
    void handleEvents();
    void draw();

private:

    int selected;
    Button* button[4];

};

#endif
