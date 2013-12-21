#ifndef SCREENS_H_
#define SCREENS_H_
#include <SFML\Graphics.hpp>
class Screens
{
public:
	virtual int Run(sf::RenderWindow&, sf::VideoMode&) = 0;
};
#endif