#include "ImageManager.h"

void ImageManager::LoadImage()
{
	sf::Image *player, *enemy, *meteor, *bg;
	player = new sf::Image();
	enemy = new sf::Image();
	meteor = new sf::Image();
	bg = new sf::Image();
	player->LoadFromFile("..\\Resources\\ship_nothrust.png");
	m_imageMap.push_back(player);
	enemy->LoadFromFile("..\\Resources\\box.png");
	m_imageMap.push_back(enemy);
	meteor->LoadFromFile("..\\Resources\\box.png");
	m_imageMap.push_back(meteor);
	bg->LoadFromFile("..\\Resources\\bg.jpg");
	m_imageMap.push_back(bg);
	m_imageMap.push_back(NULL);
}
sf::Image* ImageManager::GetImage(int id)
{
	return m_imageMap[id];
}

