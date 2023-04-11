#ifndef _GAME_HPP
#define _GAME_HPP
#include "SDL2/SDL.h"

class Game
{
public:
	Game();
	~Game();
	bool init(char* const title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	//void update();
	void handleEvents();
	void clean();
	bool getRunning() const;

private:
	bool _running;
	SDL_Window* _window;
	SDL_Renderer *_renderer;
	SDL_Texture *_texture;
	SDL_Rect _srcRect;
	SDL_Rect _destRectangle;

};
#endif 
