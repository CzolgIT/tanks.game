#include "Main.h"

Menu::Menu( SDL_Renderer* r , Text* t , Configuration* c ) : Scene( r , t , c )
{
    selected = 1;
    logo = new Texture( renderer , "assets/logo.png" );
    button = new Texture( renderer , "assets/button.png" );
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
    int f = configuration->getDisplayMode()->refresh_rate;
    int j = (int)((float)h/36);
    float s = configuration->getScale();

    SDL_SetRenderDrawColor( renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( renderer );
    text->setAlignment( true );

    auto* lgc = new SDL_Rect{0,0,logo->getWidth(),logo->getHeight()};
    auto* btc = new SDL_Rect{0,0,button->getWidth(),button->getHeight()};

    logo->render( renderer , w/2-logo->getWidth()*j/240,4*j, lgc ,0 , nullptr , SDL_FLIP_NONE , (float)j/120 );

    button->render( renderer , w/2-button->getWidth()*j/170,17*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );
    button->render( renderer , w/2-button->getWidth()*j/170,21*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );
    button->render( renderer , w/2-button->getWidth()*j/170,25*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );
    button->render( renderer , w/2-button->getWidth()*j/170,29*j, btc ,0 , nullptr , SDL_FLIP_NONE , (float)j/85 );

    text->setColor( C_WHITE );
    text->setSize( int(1.7*(float)j) );

    text->draw( "Multiplayer" , w/2 , 18*j );
    text->draw( "Singleplayer" , w/2 , 22*j );
    text->draw( "Settings" , w/2 , 26*j );
    text->draw( "Exit" , w/2 , 30*j );

    switch( selected )
    {
        case 1: text->draw( "- Multiplayer -" , w/2 , 18*j ); break;
        case 2: text->draw( "- Singleplayer -" , w/2 , 22*j ); break;
        case 3: text->draw( "- Settings -" , w/2 , 26*j ); break;
        case 4: text->draw( "- Exit -" , w/2 , 30*j ); break;
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
