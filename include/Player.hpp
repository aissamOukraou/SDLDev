#ifndef _PLAYER_
#define _PLAYER_

#include "../include/GameObjects.hpp"

class Player: public GameObject
{
public:
    Player();
    ~Player();
    void draw();
    void update();
    void clean();
private:


};



#endif