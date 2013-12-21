#ifndef BULLET_H_
#define BULLET_H_
#include "BaseEntity.h"
#include "BulletType.h"
#include "Vector2D.h"

#include "EnemyShip.h"

#include <SFML\Graphics.hpp>


#include <iostream>
#include <vector>


#include "PlayerShip.h"
#include "StateManager.h"
#include "BulletStates.h"
//class EnemyShip;
using namespace sf;
using namespace std;
//class PlayerShip;
class Bullet:public BaseEntity
{
private:
	int m_bulletType;
	bool m_fired;
	bool m_hit;
	bool m_loaded;
	Vector2D m_bulletPosition;
	Vector2D m_bulletVelocity;
	float m_bulletSpeed;
	Sprite m_bulletSprite;
	Image m_bulletNormal;
	Image m_bulletHit;
	vector<Bullet> m_bulletVector;
	StateManager<Bullet> *m_stateManager;
public:
	
	Bullet():BaseEntity(bullets)
	{
		
	}
	
	Bullet(int id, VideoMode vMode, PlayerShip *playerShip, int type):BaseEntity(id)
	{
	
		m_hit = false;
		m_fired = false;
		m_bulletType = type;
		m_bulletSpeed = -1000;
		if(m_bulletType == pistol)
		{
		m_bulletNormal.LoadFromFile("..\\Resources\\pistol.png");
		m_bulletHit.LoadFromFile("..\\Resources\\bulexplode.png");
		m_bulletSprite.SetImage(m_bulletNormal);
		}
		if(m_bulletType == laser)
		{
		//m_bulletNormal.LoadFromFile("box.png");
		//m_bulletHit.LoadFromFile("bulexplode.png");
		m_bulletSprite.SetImage(m_bulletNormal);
		}//m_loaded = true;
		m_bulletSprite.SetPosition(playerShip->GetPositionX() + playerShip->GetSizeX()/2 - 5, playerShip->GetPositionY() - 10); 
		m_bulletSprite.SetCenter(playerShip->GetCenterX(), playerShip->GetCenterY());
		m_stateManager = new StateManager<Bullet>(this);
		m_stateManager->SetCurrentState(HasNotHit::Instance());
	}
	
	//Bullet(int id, EnemyShip playerShip, int type):BaseEntity(id)
	//{
	//
	//	m_hit = false;
	//	m_fired = false;
	//	m_bulletType = type;
	//	m_bulletSpeed = -1000;
	//	if(m_bulletType == pistol)
	//	{
	//	m_bulletNormal.LoadFromFile("..\\Resources\\pistol.png");
	//	m_bulletHit.LoadFromFile("..\\Resources\\bulexplode.png");
	//	m_bulletSprite.SetImage(m_bulletNormal);
	//	}
	//	if(m_bulletType == laser)
	//	{
	//	//m_bulletNormal.LoadFromFile("box.png");
	//	//m_bulletHit.LoadFromFile("bulexplode.png");
	//	m_bulletSprite.SetImage(m_bulletNormal);
	//	}//m_loaded = true;
	//	m_bulletSprite.SetPosition(0,0); //playerShip.GetPositionX() + playerShip.GetSizeX()/2 - 5, playerShip.GetPositionY() - 10
	//	m_bulletSprite.SetCenter(0,0);//playerShip.GetCenterX(), playerShip.GetCenterY()
	//	m_stateManager = new StateManager<Bullet>(this);
	//	m_stateManager->SetCurrentState(HasNotHit::Instance());
	//}
	void RegisterBullet(Bullet bullet)
	{
		m_bulletVector.push_back(bullet);
	}

	bool IsHit()
	{
		return m_hit;
	}
	void Destroyed()
	{
		m_bulletSprite.SetImage(m_bulletHit);
	}

	StateManager<Bullet>* GetStateManager()
	{
		return m_stateManager;
	}
	void Unload()
	{
		m_loaded = false;
	}
	void ChangeType(int type)
	{
		switch(type)
		{
			case pistol:
					if(!m_loaded)
					{
					m_bulletNormal.LoadFromFile("..\\Resources\\pistol.png");
					m_bulletHit.LoadFromFile("..\\Resources\\explode.png");
					m_bulletSprite.SetImage(m_bulletNormal);
					m_loaded = true;
					}
			case laser:
				
					m_bulletNormal.LoadFromFile("..\\Resources\\box.png");
					m_bulletHit.LoadFromFile("..\\Resources\\explode.png");
					m_bulletSprite.SetImage(m_bulletNormal);
					m_loaded = true;
				
			case bomb:
				m_bulletNormal.LoadFromFile("..\\Resources\\pistol.png");
				m_bulletHit.LoadFromFile("..\\Resources\\explode.png");
				m_bulletSprite.SetImage(m_bulletNormal);
				m_loaded = true;
		}

	}

	void UpdateAI()
	{
		m_stateManager->Update();
	}
	float GetPositiony()
	{
		return m_bulletSprite.GetPosition().y;
	}
	Sprite GetSprite()
	{
		return m_bulletSprite;
	}
	void Draw(RenderWindow *win, Bullet *bullet)
	{
		//bullet->GetBulletSprite().SetPosition(m_bulletPosition.x, m_bulletPosition.y);
		/*for(int i = 0; i<m_bulletVector.size(); i++)
		{
			win->Draw(m_bulletVector[i].GetBulletSprite());
		}*/
		win->Draw(bullet->GetBulletSprite());
		
	}

	void HasHit()
	{
		m_bulletSprite.SetImage(m_bulletHit);
	}
	void Hit()
	{
		m_hit = true;
	}

	void Draw(RenderWindow *win, PlayerShip *playerShip)
	{
		//m_bulletSprite.SetPosition(m_bulletPosition.x, m_bulletPosition.y); 
		win->Draw(m_bulletSprite);
	}
	Sprite GetBulletSprite()
	{
		return m_bulletSprite;
	}
	void UpdateBullet(float time)
	{
		m_bulletSprite.Move(0, m_bulletSpeed*time);		
	}
	bool IsFired()
	{
		return m_fired;
	}
	void Fired()
	{
		m_fired = true;
	}
};
#endif