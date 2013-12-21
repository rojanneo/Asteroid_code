#include "Menu.h"
using namespace sf;
using namespace std;
Menu::Menu()
{}
Menu::~Menu()
{}
int Menu::Run(sf::RenderWindow &win, sf::VideoMode &vMode)
{	
	/*int  i = 400000000;
	char s[5];
	string t = itoa(i,s,10);
	cout<<t;*/
	bool running = true;
	sf::String menu;
	menu.SetText("Press Enter to Start");
	sf::Event Event;
	Image menuImagebg;
	menuImagebg.LoadFromFile("..\\Resources\\asteroid.jpg");
	Image startImg;
	startImg.LoadFromFile("..\\Resources\\asteroid_start.jpg");
	Image startHoverImg;
	startHoverImg.LoadFromFile("..\\Resources\\asteroid_start_hover.jpg");
	Image exitImg;
	exitImg.LoadFromFile("..\\Resources\\asteroid_exit.jpg");
	Image exitHoverImg;
	exitHoverImg.LoadFromFile("..\\Resources\\asteroid_exit_hover.jpg");
	Sprite start(startImg);
	start.SetCenter((float)startImg.GetWidth()/2, (float)startImg.GetHeight()/2);
	start.SetPosition(900,450);
	Sprite exit(exitImg);
	exit.SetCenter((float)exitImg.GetWidth()/2, (float)exitImg.GetHeight()/2);
	exit.SetPosition(910,506);
	Sprite menuSpritebg(menuImagebg);
	Sprite selector;
	selector.SetPosition(start.GetPosition());
	bool moved = false;
	//Load all the fancy menu here
while (running)
{
	while(win.GetEvent(Event))
	{

		if(Event.Type == sf::Event::Closed)
		{
			win.Close();
			return -1;
		}
		/*if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
		{
			win.Close();
			return -1;
		}*/
		if(((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Return)) && selector.GetPosition().y == start.GetPosition().y)
		{
			return 1;
		}
		else if(((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Return)) && selector.GetPosition().y == exit.GetPosition().y)
		{
			return -1;
		}
		
		if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Down))
		{
			if(selector.GetPosition().y==start.GetPosition().y)
			{
				//win.Close();
				selector.SetPosition(exit.GetPosition().x, exit.GetPosition().y);
			}
		}
		
		if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Up))
		{
			if(selector.GetPosition().y==exit.GetPosition().y)
			{
				//win.Close();
				selector.SetPosition(start.GetPosition().x, start.GetPosition().y);
			}
		}
	
	}


	
	if(start.GetPosition().x>=400)
	{
		start.Move(-1000*win.GetFrameTime(), 0);
		selector.Move(-1000*win.GetFrameTime(), 0);
	}
	if(exit.GetPosition().x>=410)
	{
		exit.Move(-1000*win.GetFrameTime(), 0);
	}
	moved = true;
	
	if(selector.GetPosition().y==start.GetPosition().y)
	{
		start.SetImage(startHoverImg);
		exit.SetImage(exitImg);
	}
	else if(selector.GetPosition().y==exit.GetPosition().y)
	{
		start.SetImage(startImg);
		exit.SetImage(exitHoverImg);
	}
	win.Clear();
	win.SetView(win.GetDefaultView());
	win.Draw(menu);
	win.Draw(menuSpritebg);
	win.Draw(start);
	win.Draw(exit);
	win.Display();
}
	return -1;
}
