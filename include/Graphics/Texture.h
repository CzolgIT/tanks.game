#ifndef Texture_h
#define Texture_h

#include "Main.h"

//Texture wrapper class
class Texture
{
public:
    Texture();
    explicit Texture( SDL_Renderer* r );
    Texture( SDL_Renderer* r , std::string path );
    ~Texture();
    
    //Loads image at specified path
    bool loadFromFile( SDL_Renderer* gRenderer , std::string path );
    
#ifdef _SDL_TTF_H
    //Creates image from font string
    bool loadFromRenderedText(  SDL_Renderer* gRenderer , TTF_Font *gFont , std::string textureText, SDL_Color textColor );
#endif
    
    //Creates blank texture
    bool createBlank( SDL_Renderer* gRenderer , int width, int height, SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING );
    
    //Deallocates texture
    void free();
    
    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    
    //Set blending
    void setBlendMode( SDL_BlendMode blending );
    
    //Set alpha modulation
    void setAlpha( Uint8 alpha );
    
    //Renders texture at given point
    void render(  SDL_Renderer* gRenderer , float x, float y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE  , float scale=1);
    
    //Set self as render target
    void setAsRenderTarget( SDL_Renderer* gRenderer );
    
    //Gets image dimensions
    int getWidth();
    int getHeight();
    
    //Pixel manipulators
    bool lockTexture();
    bool unlockTexture();
    void* getPixels();
    void copyPixels( void* pixels );
    int getPitch();
    Uint32 getPixel32( unsigned int x, unsigned int y );
    
    std::string getText();
    void setText( std::string newtext );
private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    
    SDL_Renderer* renderer;
    
    void* mPixels;
    int mPitch;
    
    std::string text; // optional
    
    //Image dimensions
    int mWidth;
    int mHeight;
};

#endif /* Texture_h */
