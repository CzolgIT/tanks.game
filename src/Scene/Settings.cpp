#include "Main.h"

Settings::Settings( SDL_Renderer* r , Text* t , Configuration* c ) : Scene( r , t , c )
{
    this->resolution = 1;
    loadDisplayModes();

}

void  Settings::handleEvents( float frameTime )
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
                    /*
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
                     */
            }
        }
    }
}

void Settings::draw( float frameTime )
{
    int w = configuration->getDisplayMode()->w;
    int h = configuration->getDisplayMode()->h;
    float s = configuration->getScale();

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );
    text->setAlignment( true );

    text->setColor( C_RED );
    text->setSize( 80 );
    text->draw( "Settings" , w/2 , 50 );

    text->setColor( C_BLACK );
    text->setSize( 40 );

    text->draw( std::to_string(w) , 50 , 10 );
    text->draw( std::to_string(h) , 50 , 40 );

    text->draw( "raz" , w/2 , 280 );
    text->draw( "dwa" , w/2 , 340 );
    text->draw( "trzy" , w/2 , 400 );

    SDL_RenderPresent( renderer );
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