#include "Main.h"

SettingsGame::SettingsGame() : _Menu(5)
{
    // najpierw buttony
    elements.push_back( new Button("kolor czolgu", 32, 13.5, 4, "mhm" ) );
    elements.push_back( new Button("albo", 32, 17.5, 4, "mhm" ) );
    elements.push_back( new Button("cos", 32, 21.5, 4, "mhm" ) );
    elements.push_back( new Button("innego", 32, 25.5, 4, "mhm" ) );
    elements.push_back( new Button("back", 32, 30, 3) );

    elements.push_back( new TextStatic("Game", 32, 3, 4, 0.2) );

    elements[selected]->setActive(true);
}

void SettingsGame::actionLeft( int s )
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
void SettingsGame::actionRight( int s )
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
