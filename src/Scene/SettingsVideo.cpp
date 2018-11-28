#include "Main.h"

SettingsVideo::SettingsVideo() : Scene()
{
    this->selected = 1;
    this->newDisplayMode = Game::configuration->getDisplayMode();
    this->newFullscreen = Game::configuration->isFullscreen();
    this->newQuality = Game::configuration->getQuality();
    this->newVsync = Game::configuration->getVsync();

    title = new TextStatic( "Video" , 3 , 4 , 0.2 );

    button[0] = new Button( "resolution" , 9.5 , strActualDisplayMode());
    button[1] = new Button( "fullscreen" , 13.5 , Game::configuration->isFullscreen() ? "yes" : "no" );
    button[2] = new Button( "quality" , 17.5 , "1.0" );
    button[3] = new Button( "vsync" , 21.5 , "yes");
    button[4] = new Button( "max fps" , 25.5 , "unlimited");
    button[5] = new Button( "back" , 30 );
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
                    if (selected == 6)
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
                        selected = 6;
                    else selected--;
                    break;
                case SDLK_DOWN:
                    if (selected == 6 )
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
                            button[0]->setComment(strActualDisplayMode());
                            std::cout << "yes";
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
                            button[0]->setComment(strActualDisplayMode());
                            std::cout << "no";
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
    SDL_SetRenderDrawColor( Game::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Game::renderer );

    title->draw();

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

std::string SettingsVideo::strActualDisplayMode()
{
    return std::to_string(Game::configuration->getDisplayMode()->w) + " x " + std::to_string(Game::configuration->getDisplayMode()->h) + " " +
        std::to_string(Game::configuration->getDisplayMode()->refresh_rate) + "hz";
}