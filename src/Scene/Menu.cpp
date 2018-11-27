#include "Main.h"

Menu::Menu(Text* t , Configuration* c ) : Scene( t , c )
{
    selected = 1;
    logo = new Texture( renderer , "assets/logo.png" );

    int h = configuration->getDisplayMode()->h;
    int j = (int)((float)h/36);

    auto* texbut = new Texture( renderer , "assets/button.png" );

    button[0] = new Button( renderer , texbut , text , "multiplayer" , configuration->getDisplayMode()->w/2 , 17*j , j , true );
    button[1] = new Button( renderer , texbut , text , "singleplayer" , configuration->getDisplayMode()->w/2 , 21*j , j , true );
    button[2] = new Button( renderer , texbut , text , "settings" , configuration->getDisplayMode()->w/2 , 25*j , j , true );
    button[3] = new Button( renderer , texbut , text , "exit" , configuration->getDisplayMode()->w/2 , 29*j , j , true );

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
    logo->render( renderer , w/2-logo->getWidth()*j/200,3*j, lgc ,0 , nullptr , SDL_FLIP_NONE , (float)j/100 );

    button[0]->draw( selected == 1 );
    button[1]->draw( selected == 2 );
    button[2]->draw( selected == 3 );
    button[3]->draw( selected == 4 );

    if (configuration->getDebug())
    {
        text->setAlignment( false );
        text->setColor( C_BLACK );
        text->setSize( j );
        text->draw( std::to_string( w )+std::string(" x ")+std::to_string( h )+std::string("  ")+std::to_string( f )+std::string("Hz") , j/6 , 35*j );
    }
    SDL_RenderPresent( renderer );

}
