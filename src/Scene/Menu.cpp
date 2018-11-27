#include "Main.h"

Menu::Menu() : Scene()
{
    Game::netManager->disconnectPlayer();
    selected = 1;

    button[0] = new Button( "multiplayer" , 17 );
    button[1] = new Button( "singleplayer" , 21 );
    button[2] = new Button( "settings" , 25 );
    button[3] = new Button( "exit" , 29 );
}

void Menu::handleEvents()
{
    while( SDL_PollEvent( &eventHandler ) != 0 )
    {
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
            }
        }
    }

}

void Menu::draw()
{
    int w = Game::configuration->getDisplayMode()->w;
    int h = Game::configuration->getDisplayMode()->h;
    int j = (int)((float)h/36);

    SDL_SetRenderDrawColor( Game::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Game::renderer );

    Game::textManager->draw("Tanks", w/2-0.3*j , 2.5*j , 6 * j , C_BLACK, true);
    Game::textManager->draw("Game", w/2-0.3*j , 8.5*j , 6 * j , C_BLACK, true);
    Game::textManager->draw("Tanks", w/2-0.5*j , 2.3*j , 6 * j , C_WHITE, true);
    Game::textManager->draw("Game", w/2-0.5*j , 8.3*j , 6 * j , C_WHITE, true);

    button[0]->draw( selected == 1 );
    button[1]->draw( selected == 2 );
    button[2]->draw( selected == 3 );
    button[3]->draw( selected == 4 );

    Game::debugger->draw();
    SDL_RenderPresent( Game::renderer );
}
