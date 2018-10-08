#include <iostream>
#include <SDL2/SDL.h>
#include "ECS.h"
#include "Game.h"


int main(int argc, char * argv[])
{
    Game * game = new Game;
    if (game->Initialize())
        game->CreateWindow(600, 400);
    else
        std::cout << "MEH\n" ;
    
    
    bool quit = false; //Main loop flag
    SDL_Event event; //Event handler
    
    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &event ) != 0 )
        {
            //User requests quit
            if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        }
        //Clear screen
        SDL_SetRenderDrawColor( game->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( game->renderer );
        
        
        // HERE WE ARE DRAWING THINGS TO SCREEN
        

        //Update screen
        SDL_RenderPresent( game->renderer );
    }
  return 0;
}
