#ifndef _GAME_HPP
#define _GAME_HPP
#include "SDL2/SDL.h"
#include "TextureManager.hpp"
#include "Player.hpp" 
#include "Enemy.hpp"
#include <vector> 

class Game
{
public:
	//SDL_Renderer* getGameRenderer() const;
	Game();
	~Game();
	bool init(char* const title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool getRunning() const;

private:
	std::vector<GameObject* > _gameObjects;//an array to the parent class and to store derived types
	GameObject *_gameObject;
	GameObject *_player;
	GameObject *_enemy1;
	//GameObject *_enemy2;
	//GameObject *_enemy3;
	bool _running;
	SDL_Window* _window; 
	SDL_Renderer *_renderer;
    //TextureManager _textureManager;
	int _currentFrame;
};

#endif 
