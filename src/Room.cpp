#include "Main.h"

Room::Room( SDL_Renderer* r , Text* t)
{
    renderer = r;
    text = t;
    selected = 1;
}

int Room::handleEvent( SDL_Event& e )
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_RETURN:
                return selected ;
                break;
            case SDLK_UP: if (selected == 1 ) selected = 2; else selected--; break;
            case SDLK_DOWN: if (selected == 2 ) selected = 1; else selected++; break;
        }
    }
    return 0;
}

void Room::draw()
{
    text->setAlignment( true );
    
    text->setColor( C_RED );
    text->setSize( 80 );
    text->draw( "Tanks Game" , 400 , 50 );
    
    text->setColor( C_BLACK );
    text->setSize( 40 );
    
    if ( selected == 1 )
        text->setColor( C_BLUE );
    else
        text->setColor( C_BLACK );
    text->draw( "Start" , 400 , 480 );
    if ( selected == 2 )
        text->setColor( C_BLUE );
    else
        text->setColor( C_BLACK );
    text->draw( "Back" , 400 , 540 );

}
