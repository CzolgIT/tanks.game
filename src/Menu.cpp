#include "Main.h"

Menu::Menu( SDL_Renderer* r , Text* t )
{
    renderer = r;
    text = t;
    //TEX_Menu = new Texture( renderer , "assets/png800x600.png" );

    clip1.x=298;
    clip1.y=272;
    clip1.w=206;
    clip1.h=63;

}

int Menu::handleEvent( SDL_Event& e )
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_SPACE: return 69; break;
        }
    }
    return 0;
}

void Menu::draw()
{
    text->setAlignment( true );
    
    text->setColor( C_RED );
    text->setSize( 80 );
    text->draw( "Tanks" , 400 , 50 );
    text->draw( "Game" , 400 , 130 );
    
    text->setColor( C_BLACK );
    text->setSize( 40 );
    text->draw( "Create room" , 400 , 280 );
    text->draw( "Join" , 400 , 340 );
    text->draw( "Settings" , 400 , 400 );
    text->draw( "Exit" , 400 , 460 );
    
    text->draw( "Press SPACE to start" , 400 , 550 );
}
