#ifndef MENU_H_
#define MENU_H_
#include "Screens.h"
#include <iostream>
class Menu:Screens
{
public:
	Menu();
	~Menu();
	int Run(sf::RenderWindow&, sf::VideoMode&);
};
#endif