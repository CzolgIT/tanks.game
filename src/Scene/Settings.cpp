#include "Main.h"

Settings::Settings() : _Menu(3)
{
    // najpierw buttony
    elements.push_back( new Button( "video" , 32 , 21.5 , 4 ) );
    elements.push_back( new Button( "game" , 32 , 25.5 , 7 ) );
    elements.push_back( new Button( "back" , 32 , 31 , 0 ) );
    elements.push_back( new TextStatic( "Settings" , 32 , 5 , 4 , 0.2 ) );

    elements[selected]->setActive(true);
}

