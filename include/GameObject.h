#ifndef GameObject_h
#define GameObject_h

#include "Main.h"

class GameObject
{
public:
    GameObject(SDL_Renderer * ren, float x, float y, int width, int height);
    // virtual void Start()
    virtual void update(){}
    virtual void move(float timeStep){}
    virtual void draw(){}
    virtual void handleEvent(SDL_Event& e){}

    Collider collider();

protected:
    SDL_Renderer* renderer;
    float x,y;
    int width,height;


};

#endif /* GameObject_h */
