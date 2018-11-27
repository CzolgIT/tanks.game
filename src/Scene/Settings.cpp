#include "Main.h"

Settings::Settings() : Scene()
{
    selected=1;
    loadDisplayModes();
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
    Game::text->setAlignment( true );

    auto* btc = new SDL_Rect{0,0,Game::textureManager->button->getWidth(),Game::textureManager->button->getHeight()};

    int center = w/2-Game::textureManager->button->getWidth()*j/170;
    Game::textureManager->button->render( center ,14*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );
    Game::textureManager->button->render( center ,18*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );
    Game::textureManager->button->render( center ,22*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );
    Game::textureManager->button->render( center ,26*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );
    Game::textureManager->button->render( center ,30*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );

    Game::text->setColor( C_WHITE );
    Game::text->setSize( int(1.7*(float)j) );

    Game::text->draw( "graphics" , w/2 , 15*j );
    Game::text->draw( "audio" , w/2 , 19*j );
    Game::text->draw( "controller" , w/2 , 23*j );
    Game::text->draw( "game" , w/2 , 27*j );
    Game::text->draw( "back" , w/2 , 31*j );

    switch( selected )
    {
        case 1: Game::text->draw( "- graphics -" , w/2 , 15*j ); break;
        case 2: Game::text->draw( "- audio -" , w/2 , 19*j ); break;
        case 3: Game::text->draw( "- controller -" , w/2 , 23*j ); break;
        case 4: Game::text->draw( "- game -" , w/2 , 27*j ); break;
        case 5: Game::text->draw( "- back -" , w/2 , 31*j ); break;
    }

    if (Game::configuration->getDebug())
    {
        Game::text->setAlignment( false );
        Game::text->setColor( C_BLACK );
        Game::text->setSize( j );
        Game::text->draw( std::to_string( w )+std::string(" x ")+std::to_string( h )+std::string("  ")+std::to_string( f )+std::string("Hz") , j/6 , 35*j );
    }
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
