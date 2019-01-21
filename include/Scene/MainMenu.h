#ifndef MainMenu_h
#define MainMenu_h

#include "Main.h"

class MainMenu : public _Menu
{
public:

    MainMenu();

    bool isNicknameSet();
    void setNickname(std::string name);

};

#endif
