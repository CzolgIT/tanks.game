#include <iostream>
#include <SDL2/SDL.h>
#include "ECS.h"
#include "Game.h"


int main(int argc, char * argv[])
{
    Game game;
    if (game.Initialize())
        game.CreateWindow(600, 400);
    
    
    while( game.isRunning )
    {
        //Handle events on queue
        while( SDL_PollEvent( &game.eventhandler ) != 0 )
        {
            //User requests quit
            if( game.eventhandler.type == SDL_QUIT )
            {
                game.isRunning = false;
            }
        }
        //Clear screen
        SDL_SetRenderDrawColor( game.renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( game.renderer );
        
        
        // HERE WE ARE DRAWING THINGS TO SCREEN
        

        //Update screen
        SDL_RenderPresent( game.renderer );
    }
  return 0;
}
