#ifndef SPLASH_H_
#define SPLASH_H_
#include "Screens.h"

class Splash:Screens
{
public:
	Splash();
	~Splash();
	int Run(sf::RenderWindow&, sf::VideoMode&);
};
#endif