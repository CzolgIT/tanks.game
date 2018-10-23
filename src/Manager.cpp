#include "Main.h"

Manager::Manager()
{
    SDL_Init( SDL_INIT_VIDEO );
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    IMG_Init( IMG_INIT_PNG );
    TTF_Init();
    
    window = SDL_CreateWindow( "Tanks Game", SCREEN_X , SCREEN_Y , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );


    TEX_Tank = new Texture( renderer , "texture.png" );
    menu = new Menu( renderer );
    player = new Player( renderer , TEX_Tank , 100 , 100 );

    running = true;
}


void Manager::close()
{
    TEX_Tank->free();
    
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;
    IMG_Quit();
    SDL_Quit();
}

void Manager::updateScreen()
{
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );

    menu->draw();
    player->draw();

    SDL_RenderPresent( renderer );
    //stepTimer.start();

}

void Manager::handleEvents()
{
    while( SDL_PollEvent( &eventHandler ) != 0 )
    {
        if( eventHandler.type == SDL_QUIT )
        {
            running = false;
        }
        player->handleEvent( eventHandler );
    }
    float timeStep = stepTimer.getTicks() / 1000.f;
    player->move( timeStep );
    stepTimer.start();
}

bool Manager::isRunning()
{
    return running;
}

