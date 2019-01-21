#ifndef MpManager_h
#define MpManager_h

#include "Main.h"

class MpManager : public _Scene
{
public:

    MpManager();

    void everyStep() override;
    void draw() override;
    void handleEvent() override;

    void reloadGUI() override;

    // globals
    static Map* map;

private:

    void CheckColliders();
    void loadFromServer();
    void sendMovement();


    NetManager * netManager;

    std::vector<Player*> players;
    std::vector<Bullet*> bullets;
    std::vector<_GameObject*> gameObjects;
    std::vector<PowerUp*> powerUps;
    std::vector<Animation*> animations;
    std::vector<TextStatic*> deads;

    EventPacket* prevEventPacket = nullptr;

    Player* myPlayer;

};

#endif
