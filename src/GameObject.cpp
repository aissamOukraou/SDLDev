#include "../include/GameObjects.hpp"
#include "../include/TextureManager.hpp"
using namespace std;
GameObject::GameObject(): _xpos(0), _ypos(0)
{

}
GameObject::~GameObject()
{

}
void GameObject::Load(int xpos, int ypos, int width, int height, string textureID)
{
    _xpos=xpos;
    _ypos=ypos;
    _width=width;
    _height=height;
    _currentFrame=1;
    _currentRow=1;
    _textureID=textureID; 
}
void GameObject::draw(SDL_Renderer* renderer)
{
    TextureManager::textureManagerInstance()->drawFrame(_textureID, _xpos, _ypos, _width, _height, renderer,0,0, SDL_FLIP_NONE);
}
void GameObject::update()
{
    _xpos+=1;
}
void GameObject::clean()
{

}
