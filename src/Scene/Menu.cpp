#include "Main.h"

Menu::Menu() : Scene()
{
    Game::netManager->disconnectPlayer();
    selected = 1;

    float j = float(Game::configuration->getDisplayMode()->h)/36;
    int c = int(double(Game::configuration->getDisplayMode()->w)/2-0.5*j);

    title[0] = new TextStatic( "Tanks" , c , int(2.3*j) , int(6 * j) , int(0.2*j) );
    title[1] = new TextStatic( "Game" , c , int(8.3*j) , int(6 * j) , int(0.2*j) );

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
