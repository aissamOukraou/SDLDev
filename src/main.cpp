#include "../include/Game.hpp"
#include "../include/TextureManager.hpp"


 int main(int argc, char** argv)
 {
	Game *game=new Game();
	game->init("Game", 100, 100, 640, 480, false);
	while( game->getRunning())
	{
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();

	//delete game;
	
 	return 0;
 }
