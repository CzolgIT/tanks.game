#ifndef GameObject_h
#define GameObject_h

#include "Main.h"

enum ObjectType : Uint8{
    STATIC = 0,
    DYNAMIC = 1
};

class _GameObject
{
public:

    _GameObject( SDL_Point position , SDL_Point dimensions , int direction , ObjectType type);
    virtual ~_GameObject() = default;
    // virtual void Start() // not used
    // virtual void update(){} // not used
    virtual void move(){}
    virtual void draw( int x0 , int y0 ){}
    virtual void handleEvent(SDL_Event& e){}
    virtual void destroy();
    void setToBeDestroyed(){ toDestroy = true; }

    SDL_Point getPosition();
    int getX();
    int getY();

    SDL_Point getDimensions();
    int getW();
    int getH();

    virtual Collider * getCollider();
    ObjectType getType();
    bool shouldBeDestroy(){ return toDestroy; }

    bool updated=false;


protected:

    SDL_Point position;
    SDL_Point dimensions;
    int direction;

    Collider * collider;
    ObjectType type;
    bool toDestroy;

};

#endif
