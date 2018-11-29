#ifndef Menu_h
#define Menu_h

#include "Main.h"

class _Menu : public _Scene
{
public:

    _Menu( int maxSelected );
    void handleEvents();
    void draw();

private:

    int flagPrevious;

    int selected;
    int maxSelected;
    std::vector<_Element*> elements; // najpierw buttony
    void updateGUI();

};

#endif
