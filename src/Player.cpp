#include "../include/Player.hpp"
#include <iostream>
using namespace std;

Player::Player()
{

}
Player::~Player()
{

}
void Player::draw()
{
    cout <<"Draw PLayer"<<endl;
    GameObject::draw();
}
void Player::update()
{
    cout <<"update Player"<<endl;
    _xpos=10;
    _ypos=20;
}
void Player::clean()
{
    cout <<"Clean Player"<<endl;
    GameObject::clean();
}