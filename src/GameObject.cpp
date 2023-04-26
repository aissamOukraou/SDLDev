#include "../include/GameObjects.hpp"
#include "../include/TextureManager.hpp"
#include <iostream>

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
    TextureManager *textureManager=TextureManager::textureManagerInstance();
    if(textureManager != nullptr)
    {
        textureManager->drawFrame(_textureID, _xpos, _ypos, _width, _height, renderer,_currentFrame,_currentRow, SDL_FLIP_NONE);
    }
    else {cout <<"DrawFrame FAILED"<<endl;} 
}
void GameObject::update()
{
    if(_xpos > 640)
    {
        _xpos-=640;
    }
    _xpos+=2;
    _currentFrame=int((SDL_GetTicks()/100)%6);
}
void GameObject::clean()
{

}
std::string GameObject::getObjectTextureID() const
{
    return _textureID;
}
