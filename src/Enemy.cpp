#include "../include/Enemy.hpp"
using namespace std;
Enemy::Enemy()
{

}
Enemy::~Enemy()
{

}
void Enemy::Load(int xpos, int ypos, int width, int height, std::string textureID)
{
    GameObject::Load(xpos, ypos, width, height, _textureID);
}
void Enemy::draw(SDL_Renderer* renderer)
{
    GameObject::draw(renderer);
}
void Enemy::update()
{
    GameObject::update();
}
void Enemy::clean()
{
    GameObject::clean();
}