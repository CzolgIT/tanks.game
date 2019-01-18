#ifndef Menu_h
#define Menu_h

#include "Main.h"

class _Menu : public _Scene
{
public:

    explicit _Menu( int maxSelected );

    void handleEvent() override;
    void draw() override;

    void reloadGUI() override;
    void exitScene() override;

    virtual void actionLeft( int s ){};
    virtual void actionRight( int s ){};

protected:

    int selected;
    int maxSelected;
    std::vector<_Element*> elements; // buttons first

};

#endif
