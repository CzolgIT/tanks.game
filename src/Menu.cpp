#include "Main.h"

Menu::Menu( SDL_Renderer* r )
{
    renderer = r;
    TEX_Menu = new Texture( renderer , "assets/png800x600.png" );

    clip1.x=298;
    clip1.y=272;
    clip1.w=206;
    clip1.h=63;

    font = TTF_OpenFont("armyrangersexpand.ttf", 30);

    //text_game = new Text(renderer, "Tanks Game" , font );
    //text_new = new Text(renderer, "New game" , font );
    //text_join = new Text(renderer, "Join" , font );
    //text_settings = new Text(renderer, "settings" , font );
    //text_exit = new Text(renderer, "exit" , font );
}

void Menu::draw()
{
    TEX_Menu->render( renderer , 0 , 0 );

    SDL_RenderDrawRect( renderer , &clip1 );

    //text_game->draw( SCREEN_WIDTH/2 , 100 );
    //text_new->draw( SCREEN_WIDTH/2 , 200 );
    //text_join->draw( SCREEN_WIDTH/2 , 300 );
    //text_settings->draw( SCREEN_WIDTH/2 , 400 );
    //text_exit->draw( SCREEN_WIDTH/2 , 500 );
}
