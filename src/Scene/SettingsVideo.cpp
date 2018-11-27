#include "Main.h"

SettingsVideo::SettingsVideo() : Scene()
{
    selected=1;
    loadDisplayModes();

    button[0] = new Button( "resolution" , 14 , true , "1920 x 1080 60hz");
    button[1] = new Button( "fullscreen" , 18 , true , Game::configuration->isFullscreen() ? "yes" : "no" );
    button[2] = new Button( "quality" , 22 , true , "1.0" );
    button[3] = new Button( "vsync" , 26 , true , "yes");
    button[4] = new Button( "back" , 30 );
}

void  SettingsVideo::handleEvents()
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
                    flagReturn = 3;
                    running = false;
                    break;
                case SDLK_RETURN:
                    if (selected == 5)
                        flagReturn = 3;
                    else
                    {
                        flagReturn = 3;
                        //update all changes
                    }
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
                case SDLK_LEFT:
                    if (selected == 1 ){}
                        // change res;
                    if (selected == 2 )
                    {
                        if (!Game::configuration->isFullscreen())
                        {
                            Game::configuration->setFullscreen(true);
                            button[1]->setComment("yes");
                        }
                    }
                    if (selected == 3 ){}
                        // change res;
                    break;
                case SDLK_RIGHT:
                    if (selected == 1 ){}
                    // change res;
                    if (selected == 2 )
                    {
                        if (Game::configuration->isFullscreen())
                        {
                            Game::configuration->setFullscreen(false);
                            button[1]->setComment("no");
                        }
                    }
                    if (selected == 3 ){}
                    // change res;
                    break;
            }
        }
    }
}

void SettingsVideo::draw()
{
    int w = Game::configuration->getDisplayMode()->w;
    int h = Game::configuration->getDisplayMode()->h;
    int j = (int)((float)h/36);

    SDL_SetRenderDrawColor( Game::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Game::renderer );

    Game::textManager->draw("Video", w/2-j/2+j/6 , 5*j , 4 * j , C_BLACK, true);
    Game::textManager->draw("Video", w/2-j/2 , 5*j-j/6 , 4 * j , C_WHITE, true);

    button[0]->draw( selected == 1 , true , true );
    button[1]->draw( selected == 2 , !Game::configuration->isFullscreen() , Game::configuration->isFullscreen() );
    button[2]->draw( selected == 3 , true , false );
    button[3]->draw( selected == 4 , true , false );
    button[4]->draw( selected == 5 );

    Game::debugger->draw();
    SDL_RenderPresent( Game::renderer );
}

void SettingsVideo::loadDisplayModes()
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
