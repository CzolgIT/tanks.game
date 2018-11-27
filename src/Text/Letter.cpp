#include "Main.h"

Letter::Letter( char character , std::string path , SDL_Color color , int size )
{
    this->character = character;
    TTF_Font* font = TTF_OpenFont( path.c_str() , size );
    std::string let;
    let[0] = character;
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, let.c_str() , color );
    this->texture = nullptr;
    if( textSurface != nullptr )
    {
        this->texture = SDL_CreateTextureFromSurface( Game::renderer , textSurface );
        this->w = textSurface->w;
        this->h = textSurface->h;
        SDL_FreeSurface( textSurface );
    }
    TTF_CloseFont( font );
}
char Letter::getCharacter()
{
    return character;
}
int Letter::getWidth()
{
    return w;
}
void Letter::draw( int x , int y )
{
    SDL_Rect rect = { x , y , w , h };
    SDL_RenderCopy( Game::renderer , texture , nullptr , &rect );
}