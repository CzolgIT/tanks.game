#ifndef GameObject_h
#define GameObject_h

#include "Main.h"


class _GameObject
{
public:

    _GameObject( SDL_Point position , SDL_Point dimensions , int direction);
    virtual ~_GameObject() = default;
    virtual void move(){}
    virtual void draw( int x0 , int y0 ){}
    virtual void handleEvent(SDL_Event& e){}
    void setToBeDestroyed(){ toDestroy = true; }

    SDL_Point getPosition();
    int getX();
    int getY();

    SDL_Point getDimensions();
    int getW();
    int getH();

    bool shouldBeDestroy(){ return toDestroy; }

    bool updated=false;


protected:

    SDL_Point position;
    SDL_Point dimensions;
    int direction;

    bool toDestroy;

};

#endif
