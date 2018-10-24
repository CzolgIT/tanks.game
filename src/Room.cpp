#include "Main.h"

Room::Room( SDL_Renderer* r , Text* t)
{
    renderer = r;
    text = t;
    selected = 1;
    selectedTank = 1;
}

int Room::handleEvent( SDL_Event& e )
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_RETURN:
                if ( selected == 1 )
                    return selectedTank;
                else
                    return selected ;
                break;
            case SDLK_UP: if (selected == 1 ) selected = 5; else selected=1; break;
            case SDLK_DOWN: if (selected == 5) selected = 1; else selected=5; break;
            case SDLK_RIGHT: if (selectedTank == 4 ) selectedTank=1; else selectedTank++; break;
            case SDLK_LEFT: if (selectedTank == 1 ) selectedTank=4; else selectedTank--; break;
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
    text->draw( "Selected tank: "+ std::to_string(selectedTank), 400 , 300 );
    
    if ( selected == 1 )
        text->setColor( C_BLUE );
    else
        text->setColor( C_BLACK );
    text->draw( "Start" , 400 , 480 );
    if ( selected == 5 )
        text->setColor( C_BLUE );
    else
        text->setColor( C_BLACK );
    text->draw( "Back" , 400 , 540 );

}
