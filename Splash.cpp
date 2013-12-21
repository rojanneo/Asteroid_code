#include "Splash.h"
#include <iostream>
using namespace sf;
Splash::Splash()
{}
Splash::~Splash()
{}
int Splash::Run(sf::RenderWindow &win, sf::VideoMode &vMode)
{
	int c = 65;
	bool running = true;
	//Clock clock;
	sf::String splashText;
	splashText.SetText("Press Any Key");
	 
	Font font;
	font.LoadFromFile("..\\Resources\\Grunge.ttf");
	splashText.SetFont(font);
	//splashText.SetColor(Color(0,0,1,0));
	splashText.SetPosition(250,500);
	sf::Event Event;
	Image splashImage;
	splashImage.LoadFromFile("..\\Resources\\asteroid.jpg");
	Sprite splashSprite(splashImage);
//	splashSprite.SetPosition(75,0);
	//splashSprite.SetCenter(splashImage.GetWidth()/2, splashImage.GetHeight()/2);
	//splashSprite.Resize(vMode.Width, vMode.Height);
	//Load all the fancy Splash here
	//clock.Reset();
	//win.SetActive(true);
	//win.SetCursorPosition(400,400);
	/*String credit1, credit2;
	credit1.SetText("Programmer: Rojan Shrestha");
	credit1.SetPosition(300, 400);
	credit2.SetText("Menu Art: Puskal Kafle");
	credit2.SetPosition(300,440);*/
	while (win.IsOpened())
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
		
		if((Event.Type == sf::Event::KeyPressed))
		{
			return 2;
		}
	}

	
	win.Clear();
	win.SetView(win.GetDefaultView());
	win.Draw(splashSprite);
	win.Draw(splashText);
	//win.Draw(credit1);
	//win.Draw(credit2);
	win.Display();
}
	return -1;
}
