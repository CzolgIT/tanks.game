#ifndef Wall_h
#define Wall_h

#include "Main.h"

class Wall : public GameObject {

public:
    Wall(SDL_Renderer* r , Texture* t , int x , int y , int width, int height);
    void move( float timeStep ) override {}
    void draw() override {}
    void handleEvent(SDL_Event& e) override {}
    void update() override {}


};

#endif
