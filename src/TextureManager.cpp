#include "../include/TextureManager.hpp"
#include "SDL2/SDL_image.h"
#include <iostream>
#include "../include/Game.hpp"
using namespace std;
typedef TextureManager TheTextureManager;

TheTextureManager* TheTextureManager::_textureManagerInstance=nullptr;

TextureManager::TextureManager()
{
}
TextureManager::~TextureManager()
{
    //delete _textureManagerInstance;
    //_textureManagerInstance=nullptr;
}
bool TextureManager::Load(char* fileName, string textureID, SDL_Renderer *renderer)
{
    SDL_Rect srcRect, destRect;
    //int width(0), height(0);
    SDL_Surface* image_surface= IMG_Load(fileName);
    if (image_surface == nullptr) 
    {
        cout <<"Loading image failed!"<<endl;
    }
    if(image_surface != nullptr)
    {
        cout <<"Image Has been Loaded Succefuly"<<endl;
        SDL_Texture* surface_texture= SDL_CreateTextureFromSurface(renderer, image_surface);
        SDL_FreeSurface(image_surface);
        if(surface_texture != nullptr)
        {
            SDL_QueryTexture(surface_texture, nullptr, nullptr, &srcRect.w, &srcRect.h);
            _textureMap[textureID]=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, srcRect.w, srcRect.h);
            SDL_SetRenderTarget(renderer, _textureMap[textureID]);
            SDL_RenderCopy(renderer, surface_texture,nullptr, nullptr);
            SDL_SetRenderTarget(renderer, nullptr);
            //SDL_RenderCopy(renderer, _textureMap[textureID],nullptr, nullptr);
            SDL_DestroyTexture(surface_texture);
            return true;
        }
    }
    else {return false;}
}
void TextureManager::draw(std::string const textureID, int xpos, int ypos, int width, int height, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = srcRect.y= 0;
    destRect.x = xpos;
    destRect.y = ypos;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    SDL_RenderCopyEx(renderer, _textureMap[textureID], &srcRect, &destRect, 0, 0, flip);
}
void TextureManager::drawFrame(std::string const textureID, int xpos, int ypos, int width, int height, SDL_Renderer *renderer, int currentFrame, int currentRow, SDL_RendererFlip flip)
{
    
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = currentFrame*width; 
    srcRect.y = (currentRow-1)*height;
    destRect.x = xpos;
    destRect.y = ypos;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    SDL_RenderCopyEx(renderer,_textureMap[textureID], &srcRect, &destRect,0,0,flip);
}  
TheTextureManager* TheTextureManager::textureManagerInstance()
{
    if(_textureManagerInstance == nullptr)
    {
        _textureManagerInstance= new TextureManager();
        return _textureManagerInstance;
    }
    else
    {
        return _textureManagerInstance;
    } 

}
SDL_Texture* TextureManager::getTextureManager( string textureID) 
{
    return _textureMap[textureID];
    //return _textureMap.find(textureID)->second;
}
