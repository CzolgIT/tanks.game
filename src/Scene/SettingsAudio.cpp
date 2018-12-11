#include "Main.h"

SettingsAudio::SettingsAudio() : _Menu(5)
{
    // najpierw buttony
    elements.push_back( new Button("master volume", 32, 13.5, 4, "mhm" ) );
    elements.push_back( new Button("music volume", 32, 17.5, 4, "mhm" ) );
    elements.push_back( new Button("effect volume", 32, 21.5, 4, "mhm" ) );
    elements.push_back( new Button("voice volume", 32, 25.5, 4, "mhm" ) );
    elements.push_back( new Button("back", 32, 30, 3) );

    elements.push_back( new TextStatic("Audio", 32, 3, 4, 0.2) );

    elements[selected]->setActive(true);
}

void SettingsAudio::actionLeft( int s )
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
void SettingsAudio::actionRight( int s )
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
