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

    virtual Collider collider();

    float getX();
    float getY();
    int getW();
    int getH();

protected:
    SDL_Renderer* renderer;
    float x,y;
    int width,height;


};

#endif /* GameObject_h */
