#include "../include/Enemy.hpp"
#include <iostream>
using namespace std;
Enemy::Enemy()
{

}
Enemy::~Enemy()
{

}
void Enemy::Load(int xpos, int ypos, int width, int height, string textureID)
{
    GameObject::Load(xpos, ypos, width, height, textureID);
}
void Enemy::draw(SDL_Renderer* renderer)
{
    GameObject::draw(renderer);
}
void Enemy::update()
{
    if(_xpos > 640 || _ypos > 480)
    {
        _xpos=0;
        _ypos=0;
    }
    cout <<"We're calling the enemy overriden update function" <<endl;
    _xpos+=1;
    _ypos+=1;
    _currentFrame=int((SDL_GetTicks()/100)%6);
}
void Enemy::clean()
{
    GameObject::clean();
}