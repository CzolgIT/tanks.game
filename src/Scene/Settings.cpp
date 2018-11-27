#include "Main.h"

Settings::Settings() : Scene()
{
    selected=1;
    loadDisplayModes();

    int scale = (int)((float)Game::configuration->getDisplayMode()->h/36);
    int center = Game::configuration->getDisplayMode()->w/2;

    button[0] = new Button( "graphics" , center , 14*scale , scale , true );
    button[1] = new Button( "audio" , center , 18*scale , scale , true );
    button[2] = new Button( "controller" , center , 22*scale , scale , true );
    button[3] = new Button( "game" , center , 26*scale , scale , true );
    button[4] = new Button( "back" , center , 30*scale , scale , true );
}

void  Settings::handleEvents()
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
                    flagReturn = 0;
                    running = false;
                    break;
                case SDLK_RETURN:
                    if (selected == 5)
                        flagReturn = 0;
                    else
                        flagReturn = 3+selected;
                    running = false;
                    break;
                case SDLK_UP:
                    if (selected == 1 )
                        selected = 5;
                    else selected--;
                    break;
                case SDLK_DOWN:
                    if (selected == 5 )
                        selected = 1;
                    else selected++;
                    break;
            }
        }
    }
}

void Settings::draw()
{
    int w = Game::configuration->getDisplayMode()->w;
    int h = Game::configuration->getDisplayMode()->h;
    int f = Game::configuration->getDisplayMode()->refresh_rate;
    int j = (int)((float)h/36);
    float s = Game::configuration->getScale();

    SDL_SetRenderDrawColor( Game::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Game::renderer );

    auto* btc = new SDL_Rect{0,0,Game::textureManager->button->getWidth(),Game::textureManager->button->getHeight()};

    int center = w/2-Game::textureManager->button->getWidth()*j/170;

    button[0]->draw( selected == 1 );
    button[1]->draw( selected == 2 );
    button[2]->draw( selected == 3 );
    button[3]->draw( selected == 4 );
    button[4]->draw( selected == 5 );

    Game::debugger->draw();
    SDL_RenderPresent( Game::renderer );
}

void Settings::loadDisplayModes()
{
    displayModeList.clear();
    int n = SDL_GetNumDisplayModes(0);
    SDL_DisplayMode mode = { SDL_PIXELFORMAT_UNKNOWN, 0, 0, 0, nullptr };
    for(int i=0; i< n ; i++)
    {
        SDL_GetDisplayMode(0, i, &mode);
        displayModeList.push_back(&mode);
    }
}
