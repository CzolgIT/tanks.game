#include "Main.h"

Menu::Menu( SDL_Renderer* r , Text* t , Configuration* c ) : Scene( r , t , c )
{
    selected = 1;
}

void Menu::handleEvents( float frameTime )
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

void Menu::draw( float frameTime )
{
    int w = configuration->getDisplayMode()->w;
    int h = configuration->getDisplayMode()->h;
    float s = configuration->getScale();

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );
    text->setAlignment( true );

    text->setColor( C_RED );
    text->setSize( (int)((float)80*s) );
    text->draw( "Tanks" , w/2 , (int)((float)50*s) );
    text->draw( "Game" , w/2 , (int)((float)130*s) );

    text->setColor( C_BLACK );
    text->setSize( 40 );

    text->draw( std::to_string( w ) , 50 , 10 );
    text->draw( std::to_string( h ) , 50 , 40 );
    text->draw( std::to_string( s ) , 150 , 70 );

    text->draw( "Multiplayer" , w/2 , 280 );
    text->draw( "Singleplayer" , w/2 , 340 );
    text->draw( "Settings" , w/2 , 400 );
    text->draw( "Exit" , w/2 , 460 );

    switch( selected )
    {
        case 1: text->draw( "- Multiplayer -" , w/2 , 280 ); break;
        case 2: text->draw( "- Singleplayer -" , w/2 , 340 ); break;
        case 3: text->draw( "- Settings -" , w/2 , 400 ); break;
        case 4: text->draw( "- Exit -" , w/2 , 460 ); break;
    }

    SDL_RenderPresent( renderer );

}
