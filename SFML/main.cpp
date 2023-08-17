#include <iostream>
#include "Game.h"

int main()
{	
	//init srand
	srand(static_cast<unsigned>(time(NULL)));
	
	//Init Game engine
	Game game;

	// Game Loop
	while (game.running() && !game.getEndGame()) 
	{
		//Update
		game.update();
		//Render
		game.render();

	}

	//End of application
	return 0;


}