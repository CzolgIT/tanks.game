#include "Main.h"

Texture::Texture()
{
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
    mPixels = nullptr;
    mPitch = 0;
}
Texture::Texture( std::string path ) : Texture()
{
    loadFromFile( path );
}
Texture::~Texture()
{
    free();
}

bool Texture::loadFromFile( std::string path )
{
    free();
    
    //The final texture
    SDL_Texture* newTexture = nullptr;
    
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == nullptr )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        return false;
    }
    else
    {
        //Convert surface to display format
        SDL_Surface* formattedSurface = SDL_ConvertSurfaceFormat( loadedSurface, SDL_PIXELFORMAT_RGBA8888, 0 );
        if( formattedSurface == nullptr )
        {
            printf( "Unable to convert loaded surface to display format! %s\n", SDL_GetError() );
        }
        else
        {
            //Create blank streamable texture
            newTexture = SDL_CreateTexture( Game::renderer , SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h );
            if( newTexture == nullptr )
            {
                printf( "Unable to create blank texture! SDL Error: %s\n", SDL_GetError() );
            }
            else
            {
                //Enable blending on texture
                SDL_SetTextureBlendMode( newTexture, SDL_BLENDMODE_BLEND );
                
                //Lock texture for manipulation
                SDL_LockTexture( newTexture, &formattedSurface->clip_rect, &mPixels, &mPitch );
                
                //Copy loaded/formatted surface pixels
                memcpy( mPixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h );
                
                //Get image dimensions
                mWidth = formattedSurface->w;
                mHeight = formattedSurface->h;
                
                //Get pixel data in editable format
                auto* pixels = (Uint32*)mPixels;
                int pixelCount = ( mPitch / 4 ) * mHeight;
                
                //Map colors
                Uint32 colorKey = SDL_MapRGB( formattedSurface->format, 0, 0xFF, 0xFF );
                Uint32 transparent = SDL_MapRGBA( formattedSurface->format, 0x00, 0xFF, 0xFF, 0x00 );
                
                //Color key pixels
                for( int i = 0; i < pixelCount; ++i )
                {
                    if( pixels[ i ] == colorKey )
                    {
                        pixels[ i ] = transparent;
                    }
                }
                
                //Unlock texture to update
                SDL_UnlockTexture( newTexture );
                mPixels = nullptr;
            }
            
            //Get rid of old formatted surface
            SDL_FreeSurface( formattedSurface );
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    
    //Return success
    mTexture = newTexture;
    return mTexture != nullptr;
}

bool Texture::loadFromRenderedText( TTF_Font *gFont , std::string textureText , SDL_Color textColor )
{
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str() , textColor );
    if( textSurface != nullptr )
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( Game::renderer , textSurface );
        if( mTexture == nullptr )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }
        
        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    else
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    
    
    //Return success
    return mTexture != nullptr;
}


void Texture::free()
{
    //Free texture if it exists
    if( mTexture != nullptr )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
        mPixels = nullptr;
        mPitch = 0;
    }
}

void Texture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    //Modulate texture rgb
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void Texture::setBlendMode( SDL_BlendMode blending )
{
    //Set blending function
    SDL_SetTextureBlendMode( mTexture, blending );
}

void Texture::setAlpha( Uint8 alpha )
{
    //Modulate texture alpha
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void Texture::render( float x, float y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip , float scale)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { (int)x, (int)y, mWidth, mHeight };
    
    //Set clip rendering dimensions
    if( clip != nullptr )
    {
        renderQuad.w = (int)((double)clip->w * scale);
        renderQuad.h = (int)((double)clip->h * scale);
    }
    
    //Render to screen
    SDL_RenderCopyEx( Game::renderer , mTexture, clip, &renderQuad, angle, center, flip );
}

int Texture::getWidth()
{
    return mWidth;
}

int Texture::getHeight()
{
    return mHeight;
}
