#include "Main.h"

SettingsController::SettingsController() : _Menu(5)
{
    // najpierw buttony
    elements.push_back( new Button("Keyboard", 32, 13.5, 4, "mhm" ) );
    elements.push_back( new Button("Mouse", 32, 17.5, 4, "mhm" ) );
    elements.push_back( new Button("Gamepad", 32, 21.5, 4, "mhm" ) );
    elements.push_back( new Button("pilot od telewizora", 32, 25.5, 4, "mhm" ) );
    elements.push_back( new Button("back", 32, 30, 3) );

    elements.push_back( new TextStatic("Controller", 32, 3, 4, 0.2) );

    elements[selected]->setActive(true);
}

void SettingsController::actionLeft( int s )
{
    switch( s )
    {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}
void SettingsController::actionRight( int s )
{
    switch( s )
    {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}
