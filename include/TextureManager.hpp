#ifndef _TEXTUREMANAGER_HPP
#define _TEXTUREMANAGER_HPP
#include "SDL2/SDL.h"
#include <string>
#include <map>
class TextureManager
{
public:
    ~TextureManager();
    static TextureManager* textureManagerInstance();//It doesn't need a instance 
    bool Load(char* filename, std::string textureID, SDL_Renderer *renderer);
    void draw(std::string const textureID, int xpos, int ypos, int width, int height, SDL_Renderer *renderer, SDL_RendererFlip flip=SDL_FLIP_NONE);
    void drawFrame(std::string const textureID, int xpos, int ypos, int width, int height, SDL_Renderer *renderer, int currentFrame, int currentRow ,SDL_RendererFlip flip=SDL_FLIP_NONE);   
private:
    static TextureManager* _textureManagerInstance;
    std::map<std::string, SDL_Texture*> _textureMap;   
    TextureManager();
};












#endif