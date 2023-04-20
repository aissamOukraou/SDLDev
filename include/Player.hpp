#ifndef _PLAYER_
#define _PLAYER_

#include "../include/GameObjects.hpp"

class Player: public GameObject
{
public:
    Player();
    ~Player();
    void Load(int xpos, int ypos, int width, int height, std::string textureID);
    void draw(SDL_Renderer* renderer);
    void update();
    void clean();
private:


};



#endif