#ifndef Settings_h
#define Settings_h

#include "Main.h"

class Settings : public _Scene
{
public:

    Settings();
    void handleEvents();
    void draw();

private:

    int selected;
    TextStatic* title;
    Button* button[5];

};

#endif
