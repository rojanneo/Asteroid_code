#include "Game.h"
#include "Bullet.h"
#include "Meteor.h"
#include "Collision.h"
#include "EnemyShip.h"
#include <math.h>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#define METEORCOUNT 5
typedef struct
{
	RenderWindow *win;
	EnemyShip* enemy;
	PlayerShip* ship;
	vector<Bullet*>Bulletvectors;
	Meteor* met[5];
	int MeteorCounts;
}Drawing;

void DrawingTHread(Drawing d)
{
		//d.win->Close();
		d.ship->Draw(d.win);
		//score.SetPosition(100,100);
		//win.Draw(score);
		if(d.enemy->GetPositionY()>d.ship->GetPositionY()-700)
			d.enemy->Draw(d.win, *d.ship);
		
		for(int i = 0; i<METEORCOUNT; i++)
		{
			
			d.met[i]->Draw(d.win);
		}
		
		if(!d.Bulletvectors.empty())
		{
			
		for(int i = 0; i<(int)d.Bulletvectors.size();i++)
		{
			//d.Bulletvectors[i]->ChangeType(type);
			d.Bulletvectors[i]->Fired();
			d.Bulletvectors[i]->Draw(d.win, d.ship);
			d.Bulletvectors[i]->UpdateBullet(d.win->GetFrameTime());
			
			
			
			d.Bulletvectors[i]->UpdateAI();
			//if(d.Bulletvectors[i]->GetPositiony()<=ship.GetPositionY()-500) win.Close();
			if(d.Bulletvectors[i]->GetPositiony()<d.ship->GetPositionY()-600)
			{
				delete d.Bulletvectors[i];
				d.Bulletvectors.erase(d.Bulletvectors.begin()+i);
				//count = d.Bulletvectors.size();
				//cout<<count<<"\n";

			}
		}
		}	
		
		d.win->SetView(d.ship->GetView());
		
		
		d.win->Display();
}
Game::Game()
{}

Game::~Game()
{}
struct enemys
	{
		EnemyShip *enemy;
		enemys(VideoMode vMode)
		{
			enemy = new EnemyShip(enemy_ship, vMode);
	
		}
	};
void Move(enemys e)
	{
		e.enemy->UpdateAI();
		
	}
int Game::Run(RenderWindow &win, VideoMode &vMode)
{
	Music m;
	SoundBuffer playerShootBuffer;
	SoundBuffer meteorBuffer;
	meteorBuffer.LoadFromFile("..\\Resources\\meteorexplosion.ogg");
	playerShootBuffer.LoadFromFile("..\\Resources\\playerShoot.ogg");
	Sound playerSound;
	Sound meteorSound;
	meteorSound.SetBuffer(meteorBuffer);
	playerSound.SetBuffer(playerShootBuffer);
	playerSound.SetLoop(false);
	meteorSound.SetLoop(false);
	m.OpenFromFile("..\\Resources\\asteroid.ogg");
	
	m.SetLoop(true);
	m.SetVolume(100);
	PlayerShip ship(player_ship, 2, vMode);
	EnemyShip enemy(enemy_ship, vMode);
	Collision col;
	Event events;
	Image bg1;
	Image bg2;
	Image bg3;
	bg1.LoadFromFile("..\\Resources\\bg.jpg");
	Image stars;
	string abc = "..\\Resources\\star.png";
	stars.LoadFromFile(abc);
	Sprite sp(bg1);
	Sprite sp2(bg1);
	Sprite sp3(bg1);
	Sprite spStar[10];
	Clock clock;
	srand((unsigned)time(0)); 
	for(int i = 0; i<10; i++)
	{
		spStar[i].SetImage(stars);
		//spStar[i].SetPosition
	}
	spStar[0].SetPosition(0,100);
	spStar[1].SetPosition(70,200);
	spStar[2].SetPosition(200,300);
	spStar[3].SetPosition(320,400);
	spStar[4].SetPosition(460,500);
	spStar[5].SetPosition(260,300);
	spStar[6].SetPosition(160,400);
	spStar[7].SetPosition(400,200);
	spStar[8].SetPosition(760,100);
	spStar[9].SetPosition(800,600);
	

	int lowestx, highestx, lowesty, highesty, rangex, rangey, random_integerx, random_integery;
	float time1 = 0;
	float time2 = 0;
	bool start = false;

	



	
	//Sprite spStar1(stars);
	//spStar1.SetPosition(spStar.GetPosition().x, spStar.GetPosition().y - spStar.GetSize().y);
	sp.Resize((float)vMode.Width, (float)vMode.Height);
	sp2.Resize((float)vMode.Width, (float)vMode.Height);
	sp2.SetPosition(sp.GetPosition().x, sp.GetPosition().y - sp.GetSize().y);
	sp3.SetPosition(sp2.GetPosition().x, sp2.GetPosition().y - sp2.GetSize().y);
	//spStar.Resize((float)vMode.Width, (float)vMode.Height);
	bool key = false;
	bool down = false;
	Bullet *bul;
	Meteor* met[METEORCOUNT];
	for(int i = 0; i<METEORCOUNT; i++)
	{
		met[i] = new Meteor(meteor, vMode);
	}
	met[0]->SetPosition(200,-400);
	met[1]->SetPosition(420,-200);
	met[2]->SetPosition(720,-400);
	met[3]->SetPosition(520,-600);
	met[4]->SetPosition(320,-400);
	/*met[5]->SetPosition(620,-400);
	met[6]->SetPosition(100,-400);
*/
	int bulletCount = 0;
	vector<Bullet*> bulletVector;
	vector<Meteor*> meteorVector;
	for(int i = 0; i<METEORCOUNT; i++)
	{
		meteorVector.push_back(met[i]);
	}
	bool fired = false;
	bool pressed = false;
	int count;
	bool change = false;
	//win.UseVerticalSync(true);
	//win.SetFramerateLimit(60);
	int type = pistol;
	Image sunImg;
	sunImg.LoadFromFile("..\\Resources\\Sun.png");
	Sprite sunSp(sunImg);
	sunSp.SetPosition(500,2000);
	//void* user;
	//int score = 0;
//	enemys e(vMode);
	
	//Thread thread(Thread::FuncType Move,void* enemy, void* &win, void* ship);
	m.Play();
	while(win.IsOpened())
	{
		
		while(win.GetEvent(events))
		{
			if(events.Type == Event::Closed)
			{
				win.Close();
				return -1;
			}
				if((events.Type == Event::KeyPressed) && (events.Key.Code == Key::Escape))
				{
					
					return 0;
				}
				if(ship.IsDestroyed() && ((events.Type == Event::KeyPressed) && (events.Key.Code == Key::Return)))
		{
			return 0;
		}
		}

		
		if(win.GetInput().IsKeyDown(Key::Up) && !ship.IsDestroyed())
		{	
			ship.Throttled();
		}
		if(!win.GetInput().IsKeyDown(Key::Up)&& !ship.IsDestroyed())
		{	
			ship.NoThrottle();
			key = false;
		}

		if(!win.GetInput().IsKeyDown(Key::Right) && !win.GetInput().IsKeyDown(Key::Up) && !ship.IsDestroyed())
		{	
			ship.NoThrottle();
		}
		if(!win.GetInput().IsKeyDown(Key::Left)&& !win.GetInput().IsKeyDown(Key::Up) && !ship.IsDestroyed())
		{	
			ship.NoThrottle();
		}
		if(win.GetInput().IsKeyDown(Key::Right) && !ship.IsDestroyed())
		{
			ship.Right();
			if(ship.GetPositionX()<=vMode.Width)
			{
				//ship.SetSpeed(100);
			ship.AddVelocity(300,0);
			ship.MoveSide(win.GetFrameTime());
			}
		}
		if(win.GetInput().IsKeyDown(Key::Left) && !ship.IsDestroyed())
		{
			ship.Left();
			if(ship.GetPositionX()>=0)
			{
			ship.AddVelocity(-300,0);
			//ship.SetSpeed(-100);
			ship.MoveSide(win.GetFrameTime());
			}
		}

		if(win.GetInput().IsKeyDown(Key::LShift))
		{
			ship.TellDestroyed();
			//ship.Destroyed();
			//win.Close();
		}
		if(win.GetInput().IsKeyDown(Key::B))
		{
			
		}
		if(win.GetInput().IsKeyDown(Key::Space) && !ship.IsDestroyed()&&!pressed)
		{
			playerSound.Play();
			bul = new Bullet(bullets, vMode, &ship, type);	
			//bul->ChangeType(type);
			//bul->ChangeType(pistol);
			bulletVector.push_back(bul);
			count = bulletVector.size();
			//cout<<count;

			pressed = true;
		}
		if(!win.GetInput().IsKeyDown(Key::Space))
		{
			pressed = false;
		}
		
		if(win.GetInput().IsKeyDown(Key::N))
		{
			
			type = laser;
			for(int i = 0; i< METEORCOUNT; i++)
			{
				met[i]->SetDestroyed();
			}
		
		}
		win.Clear();
		
		
		

		ship.MoveUp(win.GetFrameTime());
		
		if(enemy.GetPositionY()>ship.GetPositionY()-500)
		{
			enemy.MoveUp(&win, ship);
			//enemy.NavigatorUp(&win, ship);
		}	//ship.Simulate(win.GetFrameTime(), key, down);
		for(int i = 0; i<10; i++)
		{
			if(spStar[i].GetPosition().y>ship.GetPositionY() + 50)
			{
				 
					lowesty=(int)ship.GetPositionY(), highesty=(int)ship.GetPositionY()-600; 
					rangey=(highesty-lowesty)+1; 
					random_integery;
	
					random_integery = lowesty+int(rangey*rand()/(RAND_MAX + 1.0)); 
					//cout << random_integery << endl;

					lowestx=0, highestx=800; 
					rangex=(highestx-lowestx)+1; 
					random_integerx;
	
					random_integerx = lowestx+int(rangex*rand()/(RAND_MAX + 1.0)); 
					//cout << random_integerx << endl;
				 
	
					spStar[i].SetPosition((float)random_integerx, (float)random_integery);
			}
		}

		for(int i = 0; i<METEORCOUNT; i++)
		{
			if(ship.GetPositionY()<=-2000)//Score compare
			{
				met[i]->ChangeSpeed();	
			}
			met[i]->Update(win.GetFrameTime());
			if(met[i]->GetPositionY()>ship.GetPositionY() + 50)
			{
					lowesty=(int)ship.GetPositionY() - 600, highesty=(int)ship.GetPositionY()-1200; 
					rangey=(highesty-lowesty)+1; 
					random_integery;
	
					random_integery = lowesty+int(rangey*rand()/(RAND_MAX + 1.0)); 
					//cout << random_integery << endl;

					lowestx=0, highestx=720; 
					rangex=(highestx-lowestx)+1; 
					random_integerx;
	
					random_integerx = lowestx+int(rangex*rand()/(RAND_MAX + 1.0)); 
				//	cout << random_integerx << endl;
					if(met[i]->IsDestroyed())
					{
						met[i]->SetAlive();
					}
					met[i]->SetPosition(random_integerx, random_integery);
					if(!ship.IsDestroyed())
					{
					ship.IncreaseScore();
					ship.UpdateScore();
					}
			}
			met[i]->UpdateAI();
		}

		

		
		if(enemy.IsFired())
		{
			
		if(col.PixelPerfectTest(enemy.GetBullet(), ship.GetSprite()))
				{
					
					//ship.TellDestroyed();
					ship.DecreaseHealth();
					if(ship.GetHealth()<=0)
					{
						ship.TellDestroyed();
					}
					enemy.BulletReset();
					enemy.NotAttacking();
				}
		}
		if(!meteorVector.empty())
		{
		for(int i = 0; i<METEORCOUNT; i++)
		{
			if(col.CircleTest(enemy.GetBullet(), meteorVector[i]->GetSprite()))
				{
					//win.Close();
					
					//ship.TellDestroyed();
					met[i]->SetDestroyed();
					meteorSound.Play();
					enemy.BulletReset();
				}
			if(col.CircleTest(ship.GetSprite(), meteorVector[i]->GetSprite()))
				{
					//win.Close();
					
					ship.TellDestroyed();
					met[i]->SetDestroyed();
					
				}
			if(col.CircleTest(ship.GetSprite(), sunSp))
				{
					//win.Close();
					
					ship.TellDestroyed();
					//met[i]->SetDestroyed();
				}

			
			if(col.PixelPerfectTest(enemy.GetSprite(), meteorVector[i]->GetSprite()))
				{
					//win.Close();
					
					enemy.DecreaseHealth(10);
					met[i]->SetDestroyed();
					meteorSound.Play();
				}
			if(col.PixelPerfectTest(enemy.GetSprite(), sunSp))
				{
					//win.Close();
					
					enemy.DecreaseHealth(20);
					//met[i]->SetDestroyed();
				}
			//
			if(col.PixelPerfectTest(meteorVector[i]->GetSprite(), enemy.GetNavigator2())||(col.PixelPerfectTest(meteorVector[i]->GetSprite(), enemy.GetNavigator3())||(col.PixelPerfectTest(sunSp, enemy.GetNavigator3()) )))
				{
					//win.Close();
					enemy.MoveLeft(1, &win, ship);
					
				}
			else if(col.PixelPerfectTest(meteorVector[i]->GetSprite(), enemy.GetNavigator1())||(col.PixelPerfectTest(meteorVector[i]->GetSprite(), enemy.GetNavigator4())||(col.PixelPerfectTest(sunSp, enemy.GetNavigator4()) )))
				{
					//win.Close();
					enemy.MoveRight(&win, ship);
					
				}
			
			else
			{
				enemy.Attacking();
				enemy.UpdatePlayerPosition(ship.GetSprite().GetPosition(), &win);
			}

			
		
			
			 
			if(!bulletVector.empty())
			{
			for(int j = 0; j< (int)bulletVector.size(); j++)
			{
				//if((bulletVector[j]->GetSprite().GetPosition().x >= meteorVector[i]->GetSprite().GetPosition().x && bulletVector[j]->GetSprite().GetPosition().x < meteorVector[i]->GetSprite().GetPosition().x +meteorVector[i]->GetSprite().GetSize().x ) && (bulletVector[j]->GetSprite().GetPosition().y >= meteorVector[i]->GetSprite().GetPosition().y && bulletVector[j]->GetSprite().GetPosition().y <  meteorVector[i]->GetSprite().GetPosition().y + meteorVector[i]->GetSprite().GetSize().x))
				//{
				//	//win.Close();
				//	bulletVector[j]->Hit();
				//	meteorVector[i]->SetDestroyed();
				//	delete bulletVector[j];
				//	bulletVector.erase(bulletVector.begin() + j);
				//}
				if(col.PixelPerfectTest(enemy.GetBullet(), ship.GetSprite()))
				{
					//ship.TellDestroyed();
					/*ship.DecreaseHealth();
					if(ship.GetHealth()<=0)
					{
						ship.TellDestroyed();
					}*/
				}
				if(col.PixelPerfectTest(bulletVector[j]->GetSprite(), enemy.GetSprite()))
				{
					enemy.DecreaseHealth();
					meteorSound.Play();
					bulletVector[j]->Hit();
					delete bulletVector[j];
					bulletVector.erase(bulletVector.begin() + j);
				}
				else if(col.PixelPerfectTest(bulletVector[j]->GetSprite(), meteorVector[i]->GetSprite()))
				{
					bulletVector[j]->Hit();
					meteorVector[i]->SetDestroyed();
					meteorSound.Play();
					delete bulletVector[j];
					bulletVector.erase(bulletVector.begin() + j);
				}

				
				//if(col.BoundingBoxTest(bulletVector[j]->GetBulletSprite(), meteorVector[i]->GetSprite()))//collision condition should be checked here bullet and other ships
				//{
				//	cout<<i<<"T";
				//	cout<<j<<"T";
				//	win.Close();
				//	bulletVector[j]->Hit();

				//}
			}
		}
		}
		}
		ship.UpdateAI();
		if(enemy.GetPositionY()>ship.GetPositionY()-700)
		enemy.UpdateAI();
		if(enemy.IsDestroyed())
		{
			lowestx=200, highestx=620; 
			rangex=(highestx-lowestx)+1; 
			random_integerx;
			random_integerx = lowestx+int(rangex*rand()/(RAND_MAX + 1.0)); 
			enemy.EnemyReset(random_integerx, ship);
			if(!ship.IsDestroyed())
			{
			ship.IncreaseScore(10);
			ship.UpdateScore();
			}
		}
		//win.Draw(sp);
		//win.Draw(sp2);
		//win.Draw(sp3);
		ship.UpdateHealth();
		Drawing drawing;
		drawing.win = &win;
		drawing.ship = &ship;
		drawing.enemy = &enemy;
		drawing.Bulletvectors = bulletVector;
		drawing.MeteorCounts = METEORCOUNT;
		for(int i = 0; i<5; i++)
		drawing.met[i] = met[i];
		win.Draw(sunSp);
		for(int i = 0; i< 10; i++)		win.Draw(spStar[i]);
		//win.Draw(spStar1);
		//ship.UpdateScore();
//		DrawingTHread(drawing);
		ship.Draw(&win);
		//score.SetPosition(100,100);
		//win.Draw(score);
		if(enemy.GetPositionY()>ship.GetPositionY()-700)
			enemy.Draw(&win, ship);
		
		for(int i = 0; i<METEORCOUNT; i++)
		{
			
			met[i]->Draw(&win);
		}
		
		if(!bulletVector.empty())
		{
			
		for(int i = 0; i<(int)bulletVector.size();i++)
		{
			//d.Bulletvectors[i]->ChangeType(type);
			bulletVector[i]->Fired();
			bulletVector[i]->Draw(&win, &ship);
			bulletVector[i]->UpdateBullet(win.GetFrameTime());
			
			
			
			bulletVector[i]->UpdateAI();
			//if(d.Bulletvectors[i]->GetPositiony()<=ship.GetPositionY()-500) win.Close();
			if(bulletVector[i]->GetPositiony()<ship.GetPositionY()-600)
			{
				delete bulletVector[i];
				bulletVector.erase(bulletVector.begin()+i);
				//count = d.Bulletvectors.size();
				//cout<<count<<"\n";

			}
		}
		}	
		
		win.SetView(ship.GetView());
		
		
		win.Display();
	}
	return 1;
}


