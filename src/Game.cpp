#include "../include/Game.hpp"
#include "SDL2/SDL_image.h"
#include <iostream>
using namespace std;
Game::Game()
{
}
Game::~Game()
{
}
bool Game::getRunning()const 
{
    return _running;
}
bool Game::init(char* const title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    SDL_Texture *surface_texture(nullptr);
    if(SDL_Init(SDL_INIT_AUDIO || SDL_INIT_VIDEO) == 0)
    {
        int flags=SDL_WINDOW_SHOWN;

        cout <<"SDL_Init succeeded"<<endl;

        if(fullscreen == true)
        {
            flags=SDL_WINDOW_FULLSCREEN;
        }
        _window= SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(_window != nullptr)
        {
            cout <<"SDL_CreateWindow Succeeded"<<endl;
            _renderer= SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
            if(_renderer != nullptr)
            {
                cout <<"SDL_CreateRenderer succeeded"<<endl;
                SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);    
            }
            else 
            {
                cout << "SDL_CreateRenderer Failed!"<<SDL_GetError()<<endl;
                return false;
            }
        }
        else 
        {
            cout <<"SDL_CreateWindow Failed!"<<SDL_GetError()<<endl;
            return false;
        }
    }
    else
    {
        cout <<"SDL_Init Failed!"<<SDL_GetError()<<endl;
        return false;
    }
    //La première utilisation avant l'introduction de TextureManager Class
    /*SDL_Surface* image_surface= IMG_Load("assets/animate-alpha.png");
    if(image_surface == nullptr)
    {
        cout <<"SDL_LoadBMP Failed."<<SDL_GetError()<<endl;
    }
    //SDL_SetRenderTarget(_renderer, nullptr);
    surface_texture= SDL_CreateTextureFromSurface(_renderer, image_surface);
    if(surface_texture == nullptr)
    {
        cout <<"SDL_CreateTextrueFromSurface Failed."<<SDL_GetError()<<endl;
    }      
    SDL_FreeSurface(image_surface);
    SDL_QueryTexture(surface_texture,nullptr, nullptr, &_srcRect.w, &_srcRect.h);
    _texture= SDL_CreateTexture(_renderer,SDL_PIXELFORMAT_RGBA8888 ,SDL_TEXTUREACCESS_TARGET,_srcRect.w, _srcRect.h);
    _srcRect.w=128;
    _srcRect.h=82;
    SDL_SetRenderTarget(_renderer,_texture);
    SDL_RenderCopy(_renderer, surface_texture, nullptr, nullptr);
    SDL_DestroyTexture(surface_texture);
    SDL_SetRenderTarget(_renderer, nullptr);
    _destRect.x=_srcRect.x=0;
    _destRect.y=_srcRect.y=0;
    _destRect.w=_srcRect.w;
    _destRect.h=_srcRect.h;*/
    cout <<"init succeeded"<<endl;
    _running= true;
    return true;
}
void Game::render()
{
    SDL_SetRenderDrawColor(_renderer, 255,255,255,255);
    //SDL_RenderClear(_renderer);
    //SDL_Point point={30,40}; 
    TextureManager *textureManager=TextureManager::textureManagerInstance();//a static method, we create The unique instance
    if(textureManager != nullptr)
    {
        //cout <<"textureManagerInstance SUCCEEDED"<<endl;
        textureManager->Load("assets/animate.png", "animate", _renderer);   
        TextureManager::textureManagerInstance()->draw("animate", 0, 0, 128, 82, _renderer, SDL_FLIP_NONE);
        TextureManager::textureManagerInstance()->drawFrame("animate", 100, 100, 128, 82, _renderer, _currentFrame, 1, SDL_FLIP_NONE);
    }
    else 
    {
        cout <<"textureManagerInstance FAILED"<<endl;
    }
    //SDL_RenderClear(_renderer);
    //SDL_RenderCopy(_renderer, _texture, &_srcRect, &_destRect);
    //_textureManager.draw("animate", 0, 0, 128, 82, _renderer, SDL_FLIP_NONE);
    //_textureManager.drawFrame("animate", 100, 100, 128, 82, _renderer, _currentFrame, 1, SDL_FLIP_NONE);
    //SDL_RenderCopyEx(_renderer, _texture, &_srcRect,&_destRect,0,nullptr, SDL_FLIP_HORIZONTAL);
    SDL_RenderPresent(_renderer);
}
void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event)) 
    {
        switch(event.type)
        {
            case SDL_QUIT:
                _running=false;
                cout <<"The main loop is broken"<<endl;
                break;
            default:
                break;
        }
    }

}
void Game::update()
{
    _currentFrame=int((SDL_GetTicks()/100)%6); 
}
void Game::clean()
{
    cout <<"Cleaning Game"<<endl;
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}
