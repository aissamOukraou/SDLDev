#ifndef _GAME_HPP
#define _GAME_HPP
#include "SDL2/SDL.h"
#include "TextureManager.hpp"
class Game
{
public:
	Game();
	~Game();
	bool init(char* const title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool getRunning() const;

private:
	bool _running;
	SDL_Window* _window;
	SDL_Renderer *_renderer;
	//TextureManager _textureManager;
	int _currentFrame;
};

#endif 
