#include "../include/Game.hpp"
#include "../include/TextureManager.hpp"


 int main(int argc, char** argv)
 {
	Game *game=new Game();
	game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
	while( game->getRunning())
	{
		game->handleEvents();
		game->update();
		game->render();
		SDL_Delay(5);
	}
	game->clean();

	delete game;
	
 	return 0;
 }
