#ifndef Texture_h
#define Texture_h

#include "Main.h"

//Texture wrapper class
class Texture
{
public:

    Texture();
    Texture( std::string path );
    ~Texture();
    
    //Loads image at specified path
    bool loadFromFile( std::string path );

    //Creates image from font string
    bool loadFromRenderedText( TTF_Font *gFont , std::string textureText, SDL_Color textColor );
    
    //Deallocates texture
    void free();
    
    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    
    //Set blending
    void setBlendMode( SDL_BlendMode blending );
    
    //Set alpha modulation
    void setAlpha( Uint8 alpha );
    
    //Renders texture at given point
    void render( float x, float y, SDL_Rect* clip = nullptr, double angle = 0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE  , float scale=1);
    
    //Gets image dimensions
    int getWidth();
    int getHeight();

private:

    SDL_Texture* mTexture;

    void* mPixels;
    int mPitch;

    //Image dimensions
    int mWidth;
    int mHeight;
};

#endif /* Texture_h */
