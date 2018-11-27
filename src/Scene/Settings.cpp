#include "Main.h"

Settings::Settings(Text* t , Configuration* c ) : Scene(t , c )
{
    selected=1;
    logo = new Texture( renderer , "assets/logo.png" );
    button = new Texture( renderer , "assets/button.png" );

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

void Settings::draw( float frameTime )
{
    int w = configuration->getDisplayMode()->w;
    int h = configuration->getDisplayMode()->h;
    int f = configuration->getDisplayMode()->refresh_rate;
    int j = (int)((float)h/36);
    float s = configuration->getScale();

    SDL_SetRenderDrawColor( renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( renderer );
    text->setAlignment( true );

    auto* lgc = new SDL_Rect{0,0,logo->getWidth(),logo->getHeight()};
    auto* btc = new SDL_Rect{0,0,button->getWidth(),button->getHeight()};

    //logo->render( renderer , w/2-logo->getWidth()*j/200,3*j, lgc ,0 , nullptr , SDL_FLIP_NONE , (float)j/100 );

    button->render( renderer , w/2-button->getWidth()*j/170,14*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );
    button->render( renderer , w/2-button->getWidth()*j/170,18*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );
    button->render( renderer , w/2-button->getWidth()*j/170,22*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );
    button->render( renderer , w/2-button->getWidth()*j/170,26*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );
    button->render( renderer , w/2-button->getWidth()*j/170,30*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );

    text->setColor( C_WHITE );
    text->setSize( int(1.7*(float)j) );

    text->draw( "graphics" , w/2 , 15*j );
    text->draw( "audio" , w/2 , 19*j );
    text->draw( "controller" , w/2 , 23*j );
    text->draw( "game" , w/2 , 27*j );
    text->draw( "back" , w/2 , 31*j );

    switch( selected )
    {
        case 1: text->draw( "- graphics -" , w/2 , 15*j ); break;
        case 2: text->draw( "- audio -" , w/2 , 19*j ); break;
        case 3: text->draw( "- controller -" , w/2 , 23*j ); break;
        case 4: text->draw( "- game -" , w/2 , 27*j ); break;
        case 5: text->draw( "- back -" , w/2 , 31*j ); break;
    }

    if (configuration->getDebug())
    {
        text->setAlignment( false );
        text->setColor( C_BLACK );
        text->setSize( j );
        text->draw( std::to_string( w )+std::string(" x ")+std::to_string( h )+std::string("  ")+std::to_string( f )+std::string("Hz") , j/6 , 35*j );
    }
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
