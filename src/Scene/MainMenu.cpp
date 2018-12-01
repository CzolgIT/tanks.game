#include "Main.h"

MainMenu::MainMenu() : _Menu(4)
{
    if (Game::netManager != nullptr)
        Game::netManager->disconnectPlayer();

    Button* button1 = new Button( "multiplayer" , 32 , 17.5 , 1 );
    Button* button2 = new Button( "singleplayer" , 32 , 21.5 , 2 );
    Button* button3 = new Button( "settings" , 32 , 25.5 , 3 );
    Button* button4 = new Button( "exit" , 32 , 31 , -1 );
    elements.push_back(button1);
    elements.push_back(button2);
    elements.push_back(button3);
    elements.push_back(button4);

    TextStatic* title0 = new TextStatic( "Tanks" , 32 , 2.3 , 6 , 0.2 );
    TextStatic* title1 = new TextStatic( "Game" , 32 , 8.3 , 6 , 0.2 );
    elements.push_back(title0);
    elements.push_back(title1);

    elements[selected]->setActive(true);
}
