#ifndef GAME_H_
#define GAME_H_
#include "Screens.h"
#include "PlayerShip.h"
#include "EntityNames.h"
#include "ImageManager.h"
#include <SFML\Graphics.hpp>
#include <conio.h>
using namespace sf;
class Game:Screens
{
public:
	Game();
	~Game();
	int Run(sf::RenderWindow&, sf::VideoMode&);
};
#endif