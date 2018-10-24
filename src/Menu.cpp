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
    //TEX_Menu->render( renderer , 0 , 0 );
    //SDL_RenderDrawRect( renderer , &clip1 );

    text->setColor( C_RED );
    text->setSize( 50 );
    text->draw( "Tanks" , 300 , 50 );
    text->draw( "Game" , 340 , 100 );
    
    text->setColor( C_BLUE );
    text->setSize( 30 );
    text->draw( "the world" , 300 , 160 );
    text->draw( "is gonna roll me" , 340 , 190 );
    
    
    text->setColor( C_BLACK );
    text->draw( "Press SPACE to start" , 220 , 550 );
    
}
