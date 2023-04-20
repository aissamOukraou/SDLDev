#ifndef _GAME_OBJECT_
#define _GAME_OBJECT_
#include "SDL2/SDL.h"
#include <string>

class GameObject
{
public:
    GameObject();
    ~GameObject();
    void Load(int xpos, int ypos, int width, int height, std::string textureID);
    void draw(SDL_Renderer* renderr);
    void update();
    void clean();
protected:
    std::string _textureID;//l'id de la texture
    int _currentFrame;
    int _currentRow;
    int _width;
    int _height;
    int _xpos;
    int _ypos;


};








#endif