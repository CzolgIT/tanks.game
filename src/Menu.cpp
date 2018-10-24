#include "Main.h"

Menu::Menu( SDL_Renderer* r , Text* t )
{
    renderer = r;
    text = t;
    
    selected = 1;
    
    //TEX_Menu = new Texture( renderer , "assets/png800x600.png" );
    //clip1.x=298;
    //clip1.y=272;
    //clip1.w=206;
    //clip1.h=63;
}

int Menu::handleEvent( SDL_Event& e )
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_RETURN: if ( selected == 1 ) return 69 ; break;
            case SDLK_UP: if (selected == 1 ) selected = 4; else selected--; break;
            case SDLK_DOWN: if (selected == 4 ) selected = 1; else selected++; break;
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
    
    if ( selected == 1 )
        text->setColor( C_BLUE );
    else
        text->setColor( C_BLACK );
    text->draw( "Create room" , 400 , 280 );
    if ( selected == 2 )
        text->setColor( C_BLUE );
    else
        text->setColor( C_BLACK );
    text->draw( "Join" , 400 , 340 );
    if ( selected == 3 )
        text->setColor( C_BLUE );
    else
        text->setColor( C_BLACK );
    text->draw( "Settings" , 400 , 400 );
    if ( selected == 4 )
        text->setColor( C_BLUE );
    else
        text->setColor( C_BLACK );
    text->draw( "Exit" , 400 , 460 );
    
    
    
    
    //text->draw( "Press SPACE to start" , 400 , 550 );
}
