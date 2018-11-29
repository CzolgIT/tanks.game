#include "Main.h"

MainMenu::MainMenu() : _Scene()
{
    if (Game::netManager != nullptr)
        Game::netManager->disconnectPlayer();
    selected = 1;

    title[0] = new TextStatic( "Tanks" , 32 , 2.3 , 6 , 0.2 );
    title[1] = new TextStatic( "Game" , 32 , 8.3 , 6 , 0.2 );

    button[0] = new Button( "multiplayer" , 32 , 17.5 , 1 );
    button[1] = new Button( "singleplayer" , 32 , 21.5 , 2 );
    button[2] = new Button( "settings" , 32 , 25.5 , 3 );
    button[3] = new Button( "exit" , 32 , 31 , -1 );

    button[selected-1]->setActive(true);
}

void MainMenu::handleEvents()
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
                    {
                        button[selected-1]->setActive(false);
                        selected = 4;
                        button[selected-1]->setActive(true);
                    }
                    else
                    {
                        button[selected-1]->setActive(false);
                        selected--;
                        button[selected-1]->setActive(true);
                    }
                    break;
                case SDLK_DOWN:
                    if (selected == 4 )
                    {
                        button[selected-1]->setActive(false);
                        selected = 1;
                        button[selected-1]->setActive(true);
                    }
                    else
                    {
                        button[selected-1]->setActive(false);
                        selected++;
                        button[selected-1]->setActive(true);
                    }
                    break;
                default:
                    break;
            }
        }
    }

}

void MainMenu::draw()
{
    SDL_SetRenderDrawColor( Game::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Game::renderer );

    title[0]->draw();
    title[1]->draw();
    button[0]->draw();
    button[1]->draw();
    button[2]->draw();
    button[3]->draw();

    Game::debugger->draw();
    SDL_RenderPresent( Game::renderer );
}

void MainMenu::updateGUI()
{
    title[0]->updateScale();
    title[1]->updateScale();

    button[0]->updateScale();
    button[1]->updateScale();
    button[2]->updateScale();
    button[3]->updateScale();
}