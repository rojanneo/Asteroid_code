#include <SFML\Graphics.hpp>
#include "Screens.h"
#include "Game.h"
#include "Menu.h"
#include "Splash.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	VideoMode vMode(800,600,32);
	RenderWindow win(vMode, "ASTEROIDS");
	win.SetFramerateLimit(120);
	//win.ShowMouseCursor(false);
	win.UseVerticalSync(false);

	int currentScreen = 0;
	Menu menu;

	Game game;

	Splash splash;
	

	while(currentScreen >= 0)
	{
		if (currentScreen == 0)
		{
			currentScreen = splash.Run(win, vMode);
			
		}
		if(currentScreen == 2)
		{
			currentScreen = menu.Run(win, vMode);
		}

		if(currentScreen == 1)
		{
			currentScreen = game.Run(win, vMode);
		}

	}

	return EXIT_SUCCESS;

	
}