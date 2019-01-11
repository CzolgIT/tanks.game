#include "Main.h"

MainMenu::MainMenu() : _Menu(4)
{
    if (Game::netManager != nullptr)
        Game::netManager->disconnectPlayer();

    // najpierw buttony
    elements.push_back( new Button( "play on sigma" , 32 , 17.5 , 1 ) );
    elements.push_back( new Button( "play on lan" , 32 , 21.5 , 2 ) );
    elements.push_back( new Button( "settings" , 32 , 25.5 , 3 ) );
    elements.push_back( new Button( "exit" , 32 , 31 , -1 ) );
    elements.push_back( new TextStatic( "Tanks" , 32 , 2.3 , 6 , 0.2 ) );
    elements.push_back( new TextStatic( "Game" , 32 , 8.3 , 6 , 0.2 ) );

    elements[selected]->setActive(true);
}
