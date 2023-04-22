#ifndef _ENEMY_
#define _ENEMY_

#include "GameObjects.hpp"

class Enemy: public GameObject
{
public: 
    void Load(int xpos, int ypos, int width, int height, std::string textureID);
    void draw(SDL_Renderer* renderer);
    void update();
    void clean();
    Enemy();
    ~Enemy();
private:

};




#endif