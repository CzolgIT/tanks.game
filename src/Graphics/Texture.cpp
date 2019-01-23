#include <utility>

#include "Main.h"

Texture::Texture()
{
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
    mPixels = nullptr;
    mPitch = 0;
    alignCenter = false;
}
Texture::Texture( std::string path )
{
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
    mPixels = nullptr;
    mPitch = 0;
    alignCenter = false;
    loadFromFile( std::move(path) );
}
Texture::~Texture()
{
    SDL_DestroyTexture( mTexture );
}

bool Texture::loadFromFile( std::string path )
{
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == nullptr )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        return false;
    }
    else
    {
        SDL_Surface* formattedSurface = SDL_ConvertSurfaceFormat( loadedSurface, SDL_PIXELFORMAT_RGBA8888, 0 );
        if( formattedSurface == nullptr )
        {
            printf( "Unable to convert loaded surface to display format! %s\n", SDL_GetError() );
        }
        else
        {
            newTexture = SDL_CreateTexture( Game::renderer , SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h );
            if( newTexture == nullptr )
            {
                printf( "Unable to create blank texture! SDL Error: %s\n", SDL_GetError() );
            }
            else
            {
                SDL_SetTextureBlendMode( newTexture, SDL_BLENDMODE_BLEND );
                SDL_LockTexture( newTexture, &formattedSurface->clip_rect, &mPixels, &mPitch );

                memcpy( mPixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h );

                mWidth = formattedSurface->w;
                mHeight = formattedSurface->h;

                auto* pixels = (Uint32*)mPixels;
                int pixelCount = ( mPitch / 4 ) * mHeight;

                Uint32 colorKey = SDL_MapRGB( formattedSurface->format, 0, 0xFF, 0xFF );
                Uint32 transparent = SDL_MapRGBA( formattedSurface->format, 0x00, 0xFF, 0xFF, 0x00 );

                for( int i = 0; i < pixelCount; ++i )
                {
                    if( pixels[ i ] == colorKey )
                    {
                        pixels[ i ] = transparent;
                    }
                }
                SDL_UnlockTexture( newTexture );
                mPixels = nullptr;
            }
            SDL_FreeSurface( formattedSurface );
        }
        SDL_FreeSurface( loadedSurface );
    }
    mTexture = newTexture;
    return mTexture != nullptr;
}

bool Texture::loadFromRenderedText( TTF_Font *gFont , std::string textureText , SDL_Color textColor )
{
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str() , textColor );
    if( textSurface != nullptr )
    {
        mTexture = SDL_CreateTextureFromSurface( Game::renderer , textSurface );
        if( mTexture == nullptr )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }
        SDL_FreeSurface( textSurface );
    }
    else
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }

    return mTexture != nullptr;
}

void Texture::draw(float x, float y, float scale, SDL_Rect *clip, double angle, SDL_Point *center)
{
    if (clip==nullptr) clip = new SDL_Rect{0,0,mWidth,mHeight};
    if (alignCenter) x = x - scale*mWidth/2;
    SDL_Rect renderQuad = { (int)x, (int)y, int(float(clip->w)*scale), int(float(clip->h)*scale) };

    SDL_RenderCopyEx( Game::renderer , mTexture, clip, &renderQuad, angle, center, SDL_FLIP_NONE );
}

void Texture::setAlignCenter(bool center) { this->alignCenter = center; }

int Texture::getWidth() { return mWidth; }
int Texture::getHeight() { return mHeight; }