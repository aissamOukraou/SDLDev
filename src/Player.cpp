#include "../include/Player.hpp"
#include <iostream>
using namespace std;

Player::Player()
{

}
Player::~Player()
{

}
void Player::Load(int xpos, int ypos, int width, int height, string textureID)
{
    GameObject::Load(xpos, ypos, width, height, textureID);
    
}
void Player::draw(SDL_Renderer* renderer)
{
    cout <<"Draw PLayer"<<endl;
    GameObject::draw(renderer);
}
void Player::update()
{
    _xpos-=1;
    GameObject::update();
    
}
void Player::clean()
{
    cout <<"Clean Player"<<endl;
    GameObject::clean();
}