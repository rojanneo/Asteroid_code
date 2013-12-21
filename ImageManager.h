#ifndef IMAGEMANAGER_H_
#define IMAGEMANAGER_H_

#include <SFML\Graphics.hpp>
#include <map>
#include <vector>
#include <set>

class ImageManager
{
private:
	//typedef std::map<int, sf::Image*> ImageMap;	
	typedef std::vector<sf::Image*> ImageMap;
	ImageMap m_imageMap;
public:
	ImageManager(){}
	void LoadImage();
	sf::Image* GetImage(int id);
};
#endif