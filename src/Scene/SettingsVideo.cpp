#include "Main.h"

SettingsVideo::SettingsVideo() : _Scene()
{
    this->selected = 1;
    this->newDisplayMode = Game::configuration->getDisplayMode();

    title = nullptr;
    info = nullptr;
    button[0] = nullptr;
    button[1] = nullptr;
    button[2] = nullptr;
    button[3] = nullptr;
    button[4] = nullptr;
    button[5] = nullptr;
    updateGUI();
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
                        if (Game::configuration->isFullscreen())
                        {
                            Game::configuration->setFullscreen(false);
                            updateGUI();
                        }
                    if (selected == 3 )
                    {
                        if ( Game::configuration->getQuality() == 0.5 )
                        {
                            Game::configuration->setQuality( 0 );
                            updateGUI();
                        }
                        if ( Game::configuration->getQuality() == 1 )
                        {
                            Game::configuration->setQuality( 0.5 );
                            updateGUI();
                        }
                    }
                    if (selected == 4 )
                    {
                        if (Game::configuration->getVsync())
                        {
                            Game::configuration->setVsync(false);
                            info = new TextStatic( "restart required" , 6 , 1 , 0.1 );
                            updateGUI();
                        }
                    }
                    break;
                case SDLK_RIGHT:
                    if (selected == 1 ){}
                    // change res;
                    if (selected == 2 )
                        if (!Game::configuration->isFullscreen())
                        {
                            Game::configuration->setFullscreen(true);
                            updateGUI();
                        }
                    if (selected == 3 )
                    {
                        if (Game::configuration->getQuality() == 0.5)
                        {
                            Game::configuration->setQuality(1);
                            updateGUI();
                        }
                        if (Game::configuration->getQuality() == 0)
                        {
                            Game::configuration->setQuality(0.5);
                            updateGUI();
                        }
                    }
                    if (selected == 4 )
                        if (!Game::configuration->getVsync())
                        {
                            Game::configuration->setVsync(true);
                            info = new TextStatic( "restart required" , 6 , 1 , 0.1 );
                            updateGUI();
                        }
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

    if (info!= nullptr) info->draw();

    button[0]->draw();// selected == 1 , true , true );
    button[1]->draw();// selected == 2 , Game::configuration->isFullscreen() , !Game::configuration->isFullscreen() );
    button[2]->draw();// selected == 3 , Game::configuration->getQuality()>0 , Game::configuration->getQuality()<1 );
    button[3]->draw();// selected == 4 , Game::configuration->getVsync() , !Game::configuration->getVsync() );
    button[4]->draw();// selected == 5 , true , true );
    button[5]->draw();// selected == 6 );

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

void SettingsVideo::updateGUI()
{
    if (info!= nullptr)
    {
        delete (info);
        info = new TextStatic( "restart required" , 32 , 7 , 1 , 0.1 );
    }


    if (title != nullptr) delete(title);
    if (button[0] != nullptr) delete(button[0]);
    if (button[1] != nullptr) delete(button[1]);
    if (button[2] != nullptr) delete(button[2]);
    if (button[3] != nullptr) delete(button[3]);
    if (button[4] != nullptr) delete(button[4]);
    if (button[5] != nullptr) delete(button[5]);

    std::string q;
    if (Game::configuration->getQuality() == 0) q="low";
    if (Game::configuration->getQuality() == 0.5) q="medium";
    if (Game::configuration->getQuality() == 1) q="high";

    title = new TextStatic( "Video" , 32 , 3 , 4 , 0.2 );
    button[0] = new Button( "resolution" , 32 , 9.5 , -10 ,strActualDisplayMode());
    button[1] = new Button( "fullscreen" , 32 , 13.5 , -10 ,Game::configuration->isFullscreen() ? "yes" : "no" );
    button[2] = new Button( "quality" , 32 , 17.5 , -10 ,q );
    button[3] = new Button( "vsync" , 32 , 21.5 , -10 ,Game::configuration->getVsync() ? "yes" : "no" );
    button[4] = new Button( "max fps" , 32 , 25.5 , -10 ,"option disabled");
    button[5] = new Button( "back" , 32 , 30 , 3 );
}