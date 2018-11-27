#include "Main.h"

Menu::Menu() : Scene()
{
    Game::netManager->disconnectPlayer();
    selected = 1;

    int scale = (int)((float)Game::configuration->getDisplayMode()->h/36);
    int center = Game::configuration->getDisplayMode()->w/2;

    button[0] = new Button( "multiplayer" , center , 17*scale , scale , true );
    button[1] = new Button( "singleplayer" , center , 21*scale , scale , true );
    button[2] = new Button( "settings" , center , 25*scale , scale , true );
    button[3] = new Button( "exit" , center , 29*scale , scale , true );
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

    Game::textManager->draw("Tanks", w/2-j/2+j/6 , 2.5*j , 6 * j , C_BLACK, true);
    Game::textManager->draw("Game", w/2-j/2+j/6 , 8.5*j , 6 * j , C_BLACK, true);
    Game::textManager->draw("Tanks", w/2-j/2 , 2.5*j-j/6 , 6 * j , C_WHITE, true);
    Game::textManager->draw("Game", w/2-j/2 , 8.5*j-j/6 , 6 * j , C_WHITE, true);

    button[0]->draw( selected == 1 );
    button[1]->draw( selected == 2 );
    button[2]->draw( selected == 3 );
    button[3]->draw( selected == 4 );

    Game::debugger->draw();
    SDL_RenderPresent( Game::renderer );
}
