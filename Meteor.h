#ifndef METEOR_H_
#define METEOR_H_

#include "MeteorStates.h"
#include "BaseEntity.h"
#include "Vector2D.h"
#include "PlayerShip.h"
#include <iostream>

using namespace sf;
using namespace std;

class Meteor:public BaseEntity
{
private:
	Image m_meteorImg;
	Sprite m_meteorSp;
	Image m_meteorDes;
	bool m_destroyed;
	float m_meteorSpeed;
	StateManager<Meteor> *m_stateManager;
public:
	Meteor(int id, VideoMode vMode):BaseEntity(id)
	{
		m_meteorImg.LoadFromFile("..\\Resources\\meteor.png");
		m_meteorDes.LoadFromFile("..\\Resources\\explode.png");
		m_meteorSp.SetImage(m_meteorImg);
		m_meteorSpeed = 50;
		m_destroyed = false;
		m_stateManager = new StateManager<Meteor>(this);
		m_stateManager->SetCurrentState(MeteorHasNotHit::Instance());
	}

	void Destroyed()
	{
		m_meteorSp.SetImage(m_meteorDes);
	}

	bool IsDestroyed()
	{
		return m_destroyed;
	}

	void SetPosition(int x, int y)
	{
		m_meteorSp.SetPosition((float)x,(float)y);	
	}

	void Update(float time)
	{
		if(!m_destroyed)
		m_meteorSp.Move(0, m_meteorSpeed*time);
	}

	void Draw(RenderWindow *win)
	{
		//if(time<1000 && !m_destroyed)
		win->Draw(m_meteorSp);
	}

	void ChangeSpeed()
	{
		m_meteorSpeed = 100;
	}

	float GetPositionX()
	{
		return m_meteorSp.GetPosition().x;
	}

	float GetPositionY()
	{
		return m_meteorSp.GetPosition().y;
	}

	StateManager<Meteor>* GetStateManager()
	{
		return m_stateManager;
	}

	void UpdateAI()
	{
		m_stateManager->Update();
	}
	void SetDestroyed()
	{
		m_destroyed = true;
	}
	void SetAlive()
	{
		m_destroyed = false;
		m_meteorSp.SetImage(m_meteorImg);
		m_stateManager->ChangeState(MeteorHasNotHit::Instance());
	}
	Sprite GetSprite()
	{
		return m_meteorSp;
	}
};

#endif