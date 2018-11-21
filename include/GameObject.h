#ifndef GameObject_h
#define GameObject_h

#include "Main.h"

// Wall
// Player
// Bullet

class GameObject
{
public:
    GameObject(SDL_Renderer * ren, float x, float y, int width, int height);
    // virtual void Start() // not used
    virtual void update(){}
    virtual void move(float timeStep){}
    virtual void draw( int x0 , int y0 ){}
    virtual void handleEvent(SDL_Event& e){}
    virtual void destroy();
    virtual Collider * getCollider();

    float getX();
    float getY();
    int getW();
    int getH();
    bool shouldBeDestroy(){ return toDestroy; }
    void setToBeDestroyed(){ toDestroy = true; }
protected:
    Collider * collider;
    SDL_Renderer* renderer;
    float x,y;
    int width,height;
    bool toDestroy = false;

};

#endif /* GameObject_h */
