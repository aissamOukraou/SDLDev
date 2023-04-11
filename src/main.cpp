#include "../include/Game.hpp"

Game *game(nullptr);

 int main(int argc, char** argv)
 {
	game= new Game();
	game->init("Chapter 1", 100, 100, 640, 480, false); 
	while( game->getRunning())
	{
		game->handleEvents();
		//game->update();
		game->render();
	}
	game->clean();

	delete game;
	
 	return 0;
 }
