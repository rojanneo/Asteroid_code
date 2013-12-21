#ifndef ENEMYSHIP_H_
#define ENEMYSHIP_H_

#include "BaseEntity.h"
#include "PlayerShip.h"
#include "StateManager.h"
#include "EnemyStates.h"
#include "Bullet.h"
#include "Collision.h"

#include <iostream>

using namespace sf;
class EnemyShip:BaseEntity
{
private:
	Image m_shipNormal;
	Image m_shipBetween;
	Image m_shipDestroyed;
	Image m_shipBullet;
	Image m_navigator1;
	Image m_navigator2;
	Sprite m_navigatorSprite1;
	Sprite m_navigatorSprite2;
	Sprite m_navigatorSprite3;
	Sprite m_navigatorSprite4;
	Sprite m_shipSprite;
	Sprite m_bulletSprite;
	float m_shipSpeed;
	int m_health;
	bool m_destroyed;
	bool m_normal;
	bool m_between;
	bool m_des;
	int m_sidespeed;
	bool m_moving;
	bool m_attacking;
	StateManager<EnemyShip> *m_stateManager;
	Vector2D m_playerPosition;
	float m_time;
	bool rotate;
	bool m_fired;
	Collision m_col;
	//EnemyBullet *bul;
	//0EnemyShip m_enemyShip;
	//Bullet *bul;
	//PlayerShip *ship;
	//std::vector<Bullet*> m_bulletVector;
public:
	EnemyShip(int id, VideoMode vMode):BaseEntity(id)
	{
		rotate = false;
		m_normal = true;
		m_between = false;
		m_des = false;
		m_stateManager = new StateManager<EnemyShip>(this);
		m_stateManager->SetCurrentState(NotHit::Instance());
		m_shipNormal.LoadFromFile("..\\Resources\\enemynormal.png");
		m_shipDestroyed.LoadFromFile("..\\Resources\\explode.png");
		m_shipBetween.LoadFromFile("..\\Resources\\enemylowhealth.png");
		m_navigator1.LoadFromFile("..\\Resources\\navigator1.png");
		m_navigator2.LoadFromFile("..\\Resources\\navigator2.png");
		m_shipBullet.LoadFromFile("..\\Resources\\enemybomb.png");
		m_shipSprite.SetImage(m_shipNormal);
		m_bulletSprite.SetImage(m_shipBullet);
		//m_shipSprite.SetCenter(m_shipNormal.GetWidth()/2, m_shipNormal.GetHeight()/2);
		m_navigatorSprite1.SetImage(m_navigator1);
		m_navigatorSprite2.SetImage(m_navigator1);
		m_navigatorSprite3.SetImage(m_navigator2);
		m_navigatorSprite4.SetImage(m_navigator2);
		m_bulletSprite.SetPosition(m_shipSprite.GetPosition().x + m_shipSprite.GetSize().x/2, m_shipSprite.GetPosition().y + m_shipSprite.GetSize().y/2);
		m_navigatorSprite1.SetCenter((float)m_navigator1.GetWidth()/2, (float)m_navigator1.GetHeight()/2);
		m_navigatorSprite2.SetCenter((float)m_navigator2.GetWidth()/2, (float)m_navigator2.GetHeight()/2);
		m_shipSpeed = -100;
		m_shipSprite.SetPosition(420, -1500 + m_shipSprite.GetSize().y/2);
		m_navigatorSprite1.SetPosition(420, -1500 - m_shipSprite.GetSize().y/2);
		m_navigatorSprite2.SetPosition(m_navigatorSprite1.GetPosition().x+m_navigatorSprite1.GetSize().x,-1500 - m_shipSprite.GetSize().y/2); 
		m_navigatorSprite3.SetPosition(m_shipSprite.GetPosition().x-m_navigator2.GetWidth(), m_shipSprite.GetPosition().y);
		m_navigatorSprite4.SetPosition(m_shipSprite.GetPosition().x+ 2 * m_navigator2.GetWidth(), m_shipSprite.GetPosition().y);
		m_destroyed = false;
		m_health = 20;
		m_sidespeed = 100;
		m_moving = false;
		m_fired = false;
		m_attacking = false;
		float x = m_shipSprite.GetPosition().x + m_shipSprite.GetSize().x;
		float y = m_shipSprite.GetPosition().y + m_shipSprite.GetSize().y;
		float cx = m_shipSprite.GetCenter().x;
		float cy = m_shipSprite.GetCenter().y;
		//bull = new Bullet();
	}
	void NotAttacking()
	{
		m_attacking = false;
	}
	Sprite GetSprite()
	{
		return m_shipSprite;
	}

	int GetHealth()
	{
		return m_health;
	}

	void CheckCollsion(PlayerShip *ship)
	{
		if(m_col.PixelPerfectTest(m_bulletSprite, ship->GetSprite()))
		{
			ship->TellDestroyed();
		}
	}

	void DecreaseHealth()
	{
		//std::cout<<m_health;
		m_health--;
		if(m_health<=0)
		{
			Destroy();

		}
	}
	bool IsAttacking()
	{
		return m_attacking;
	}

	void Attacking()
	{
		m_attacking = true;
	}
	void DecreaseHealth(int x)
	{
		m_health = m_health - x;
		if(m_health<=0)
		{
			Destroy();
		}
	}

	void UpdatePlayerPosition(Vector2f f, RenderWindow *win)
	{
		m_playerPosition.x = f.x;
		m_time = win->GetFrameTime();
		m_playerPosition.y = f.y;
	}
	Sprite GetNavigator3()
	{
		return m_navigatorSprite3;
	}
	Sprite GetNavigator4()
	{
		return m_navigatorSprite4;
	}
	Sprite GetNavigator1()
	{
		return m_navigatorSprite1;
	}
	Sprite GetNavigator2()
	{
		return m_navigatorSprite2;
	}
	void Destroy()
	{
		//std::cout<<"Destroyed";
		m_destroyed = true;
	}

	void BulletReset()
	{
		m_bulletSprite.SetPosition(m_shipSprite.GetPosition().x + m_shipSprite.GetSize().x/2, m_shipSprite.GetPosition().y + m_shipSprite.GetSize().y);
		m_fired = false;
	}
	void EnemyReset(int x, PlayerShip ship)
	{
		m_shipSprite.SetImage(m_shipNormal);
		m_stateManager->ChangeState(NotHit::Instance());
		m_shipSprite.SetPosition((float)x,(float)ship.GetPositionY()-1200);
		m_navigatorSprite1.SetPosition(m_shipSprite.GetPosition().x, m_shipSprite.GetPosition().y-72);
		m_navigatorSprite2.SetPosition(m_navigatorSprite1.GetPosition().x + m_navigatorSprite2.GetSize().x, m_navigatorSprite1.GetPosition().y);
		m_navigatorSprite3.SetPosition(m_shipSprite.GetPosition().x-m_navigator2.GetWidth(), m_shipSprite.GetPosition().y);
		m_navigatorSprite4.SetPosition(m_shipSprite.GetPosition().x+ 2 * m_navigator2.GetWidth(), m_shipSprite.GetPosition().y);
		m_destroyed = false;
		BulletReset();
		m_health = 10;
		m_normal = true;
		m_des = false;
		m_between = false;
		m_attacking = false;
	}
	bool IsDestroyed()
	{
		return m_destroyed;
	}
	void DestroyedImage()
	{
		if(!m_des)
		m_shipSprite.SetImage(m_shipDestroyed);
		m_des = true;
	}
	void HealthImage()
	{
		if(!m_between)
		m_shipSprite.SetImage(m_shipBetween);
		m_between = true;
	}
	void MoveLeft(int dir, RenderWindow *win, PlayerShip ship)
	{
		
		//std::cout<<"NOT ATTACKING";
		if(m_shipSprite.GetPosition().x>=50)//change
		{
			m_sidespeed = 300;
			m_shipSprite.Move(-m_sidespeed * win->GetFrameTime(), 0);
			m_navigatorSprite1.Move(-m_sidespeed * win->GetFrameTime(), 0);
			m_navigatorSprite2.Move(-m_sidespeed * win->GetFrameTime(), 0);	
			m_navigatorSprite3.Move(-m_sidespeed * win->GetFrameTime(), 0);	
			m_navigatorSprite4.Move(-m_sidespeed * win->GetFrameTime(), 0);	
			//m_moving = true;
			m_attacking = false;
		}
		//	else
		//	{
		//		m_sidespeed = 300;
		//		m_shipSprite.Move(-m_sidespeed * win->GetFrameTime(), 0);
		//		m_navigatorSprite.Move(-m_sidespeed * win->GetFrameTime(), 0);
		//		m_moving = true;
		//	}
		//}
		//else 
		//{
		//	if(!m_moving)
		//	{
		//	if(ship.GetSpeed()==100)
		//	{
		//		m_sidespeed = 100;
		//		m_shipSprite.Move(m_sidespeed * win->GetFrameTime(), 0);
		//		m_navigatorSprite.Move(m_sidespeed * win->GetFrameTime(), 0);
		//		m_moving = true;
		//	}
		//	else
		//	{
		//		m_sidespeed = 300;
		//		m_shipSprite.Move(m_sidespeed * win->GetFrameTime(), 0);
		//		m_navigatorSprite.Move(m_sidespeed * win->GetFrameTime(), 0);
		//		m_moving = true;
		//	}
		//	}
		//}
	}

	void MoveRight(RenderWindow *win, PlayerShip ship)
	{
		if(m_shipSprite.GetPosition().x<=720)//change
		{
			m_sidespeed = 300;
			m_shipSprite.Move(m_sidespeed * win->GetFrameTime(), 0);
			m_navigatorSprite1.Move(m_sidespeed * win->GetFrameTime(), 0);
			m_navigatorSprite2.Move(m_sidespeed * win->GetFrameTime(), 0);
			m_navigatorSprite3.Move(m_sidespeed * win->GetFrameTime(), 0);
			m_navigatorSprite4.Move(m_sidespeed * win->GetFrameTime(), 0);
				//m_moving = true;
			m_attacking = false;
			//std::cout<<"Not ATTACKING";
		}
	}
	bool IsFired()
	{
		return m_fired;
	}
	void Attack()
	{
		
		//bul = new EnemyBullet(this);
		m_fired = true;
		//std::cout<<"ATTACK\n";
		float differenceX = m_playerPosition.x - m_bulletSprite.GetPosition().x;
			float differenceY = m_playerPosition.y - m_bulletSprite.GetPosition().y;
			float differenceAngle = atan2(differenceY, differenceX); // in radians
			float velocityx = cos(differenceAngle) * 100; // 100 is the speed you want to move towards the target point
			float velocityy = sin(differenceAngle) * 100;
				//sp.Rotate(theta);
			if(!rotate)
			{
			//m_bulletSprite.Rotate((float)differenceAngle*(180/3.14));
			rotate = true;
			}
			else
			{
				//m_bulletSprite.Rotate(-differenceAngle*(180/3.14));
				rotate = false;
			
			}
			m_bulletSprite.Move(velocityx * m_time, velocityy * m_time );
			
			if(m_bulletSprite.GetPosition().y>=m_playerPosition.y + 50)
			{
				BulletReset();
			}
		//bul = new Bullet(bullets, x, y, cx, cy, pistol); 	
		//	//bul->ChangeType(type);
		//	//bul->ChangeType(pistol);
		//m_bulletVector.push_back(bul);
		//std::cout<<m_bulletVector.size();

	}
	Sprite GetBullet()
	{
		return m_bulletSprite;
	}

	void NotMoving()
	{
		m_moving = false;
	}
	StateManager<EnemyShip>* GetStateManager()
	{
		return m_stateManager;
	}

	void UpdateAI()
	{
		m_stateManager->Update();
	}

	void Draw(RenderWindow *win, PlayerShip ship)
	{
		//if(!m_destroyed)
		win->Draw(m_bulletSprite);

		win->Draw(m_shipSprite);
				/*win->Draw(m_navigatorSprite3);
		win->Draw(m_navigatorSprite4);
		win->Draw(m_navigatorSprite2);
		win->Draw(m_navigatorSprite1);
*/
	}
	void MoveUp(RenderWindow *win, PlayerShip ship)
	{
		//Thread thread(this.MoveUp());

		
			m_shipSprite.Move(0,  -ship.GetSpeed() * win->GetFrameTime());
			m_navigatorSprite1.Move(0,  -ship.GetSpeed() * win->GetFrameTime());
			m_navigatorSprite2.Move(0,  -ship.GetSpeed() * win->GetFrameTime());
			m_navigatorSprite3.Move(0,  -ship.GetSpeed() * win->GetFrameTime());
			m_navigatorSprite4.Move(0,  -ship.GetSpeed() * win->GetFrameTime());
		
	}
	void NavigatorUp(RenderWindow *win, PlayerShip ship)
	{
			m_navigatorSprite1.Move(0,  -ship.GetSpeed() * win->GetFrameTime());
	}
	float GetPositionY()
	{
		return m_shipSprite.GetPosition().y;
	}
	float GetPositionX()
	{
		return m_shipSprite.GetPosition().x;
	}
	float GetSizeX()
	{
		return m_shipSprite.GetSize().x;
	}
	float GetSizeY()
	{
		return m_shipSprite.GetSize().y;
	}
	float GetCenterX()
	{
		return m_shipSprite.GetCenter().x;
	}

	float GetCenterY()
	{
		return m_shipSprite.GetCenter().y;
	}
	bool test()
	{
		return m_attacking;
	}
};
#endif