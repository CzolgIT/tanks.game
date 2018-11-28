#include "Main.h"

Menu::Menu() : _Scene()
{
    if (Game::netManager != nullptr)
        Game::netManager->disconnectPlayer();
    selected = 1;

    title[0] = nullptr;
    title[1] = nullptr;
    button[0] = nullptr;
    button[1] = nullptr;
    button[2] = nullptr;
    button[3] = nullptr;
    updateGUI();
}

void Menu::handleEvents()
{
    while( SDL_PollEvent( &eventHandler ) != 0 )
    {
        if( eventHandler.type == SDL_WINDOWEVENT )
        {
            if (eventHandler.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
            {
                Game::configuration->resizeWindow();
                updateGUI();
            }
        }
        if( eventHandler.type == SDL_QUIT )
        {
            running = false;
            flagReturn = -1;
            break;
        }
        if( eventHandler.type == SDL_KEYDOWN && eventHandler.key.repeat == 0 )
        {
            switch( eventHandler.key.keysym.sym )
            {
                case SDLK_ESCAPE:
                    flagReturn = -1;
                    running = false;
                    break;
                case SDLK_RETURN:
                    if (selected == 4)
                        flagReturn = -1;
                    else
                        flagReturn = selected;
                    running = false;
                    break;
                case SDLK_UP:
                    if (selected == 1 )
                        selected = 4;
                    else selected--;
                    break;
                case SDLK_DOWN:
                    if (selected == 4 )
                        selected = 1;
                    else selected++;
                    break;
                default:
                    break;
            }
        }
    }

}

void Menu::draw()
{
    SDL_SetRenderDrawColor( Game::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Game::renderer );

    title[0]->draw();
    title[1]->draw();

    button[0]->draw( selected == 1 );
    button[1]->draw( selected == 2 );
    button[2]->draw( selected == 3 );
    button[3]->draw( selected == 4 );

    Game::debugger->draw();
    SDL_RenderPresent( Game::renderer );
}

void Menu::updateGUI()
{
    if (title[0] != nullptr) delete(title[0]);
    if (title[1] != nullptr) delete(title[1]);
    if (button[0] != nullptr) delete(button[0]);
    if (button[1] != nullptr) delete(button[1]);
    if (button[2] != nullptr) delete(button[2]);
    if (button[3] != nullptr) delete(button[3]);

    title[0] = new TextStatic( "Tanks" , 2.3 , 6 , 0.2 );
    title[1] = new TextStatic( "Game" , 8.3 , 6 , 0.2 );

    button[0] = new Button( "multiplayer" , 17.5 );
    button[1] = new Button( "singleplayer" , 21.5 );
    button[2] = new Button( "settings" , 25.5 );
    button[3] = new Button( "exit" , 31 );
}