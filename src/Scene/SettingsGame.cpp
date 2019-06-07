#include "Main.h"

SettingsGame::SettingsGame() : _Menu(2)
{
    elements.push_back( new Button("Change nickname", 32, 25.5, 5, Game::configuration->getNickname()) );
    elements.push_back( new Button("back", 32, 30, 3) );

    elements.push_back( new TextStatic("Game", 32, 3, 4, 0.2) );

    elements[selected]->setActive(true);
}

void SettingsGame::actionLeft( int s )
{
    switch( s )
    {
        default:
            break;
    }
}
void SettingsGame::actionRight( int s )
{
    switch( s )
    {
        default:
            break;
    }
}
