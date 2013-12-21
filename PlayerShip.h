#ifndef PLAYERSHIP_H_
#define PLAYERSHIP_H_
#include "BaseEntity.h"
#include "Vector2D.h"
#include "StateManager.h"
#include "PlayerStates.h"
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;
class PlayerShip:public BaseEntity
{
private:
	Sprite m_shipSprite;
	float m_shipInverseMass;
	Vector2D m_shipVelocity;
	Vector2D m_shipPosition;
	Vector2D m_shipAcceleration;
	float m_shipDamping;
	Vector2D m_shipForce;
	Image m_shipImage0;
	Image m_shipImage1;
	Image m_shipImage2;
	Image m_shipImage3;
	Image m_shipImage4;
	View m_view;
	String m_gameOver;
	bool m_isDestroyed;
	float m_shipSpeed;
	int m_shipHealth;
	int m_score;
	String score;
	std::string s;
	char buffer[5];
	String scoreTitle;
	String health;
	String healthTitle;
	StateManager<PlayerShip>* m_stateManager;
public:
	
	PlayerShip(int id, float mass, VideoMode vMode):BaseEntity(id)
	{
		m_shipSpeed = 100;
		m_shipHealth = 10;
		m_isDestroyed = false;
		m_view.SetCenter((float)vMode.Width/2, (float)vMode.Height/2);
		m_view.SetHalfSize((float)vMode.Width/2, (float)vMode.Height/2);
		m_shipImage0.LoadFromFile("..\\Resources\\ship_nothrust.png");
		m_shipImage1.LoadFromFile("..\\Resources\\ship_thrust.png");
		m_shipImage2.LoadFromFile("..\\Resources\\ship_right.png");
		m_shipImage3.LoadFromFile("..\\Resources\\ship_left.png");
		m_shipImage4.LoadFromFile("..\\Resources\\explode.png");
		m_shipInverseMass = (1/mass);
		m_shipSprite.SetImage(m_shipImage4);
		//m_shipSprite.SetCenter((float)m_shipImage0.GetWidth()/2, (float)m_shipImage0.GetHeight()/2);
		//m_shipSprite.SetPosition(400, 600-image.GetHeight()/2);
		m_shipPosition.x = 400;
		m_shipPosition.y = (float)(600-m_shipImage0.GetHeight()/2 - 50);
		//m_shipSprite.SetPosition(400,(float)(600-m_shipImage0.GetHeight()/2 - 50));
		m_shipVelocity.x = 0;
		m_shipVelocity.y = 0;	
		m_shipForce.x = 0;
		m_shipForce.y = 0;
		m_shipAcceleration.x = 0;
		m_shipAcceleration.y = 1;
		m_shipDamping = 0.9f;
		m_gameOver.SetText("Game Over Press Enter");
		m_stateManager = new StateManager<PlayerShip>(this);
		m_stateManager->SetCurrentState(IsAlive::Instance());
		m_score = 0;
		score.SetText("0");
		
		score.SetPosition(scoreTitle.GetPosition().x + 100, scoreTitle.GetPosition().y);
		scoreTitle.SetText("Score: ");
		healthTitle.SetText("Health: ");
		healthTitle.SetPosition(650,0);
		health.SetPosition(healthTitle.GetPosition().x+100, healthTitle.GetPosition().y);
	}
	PlayerShip(int id):BaseEntity(id)
	{}
	int GetScore()
	{
		return m_score;
	}

	void IncreaseScore()
	{
		m_score++;
		
	}
	void UpdateScore()
	{
		s = _itoa(m_score, buffer, 10);
		//std::cout<<s;
		score.SetText(s);
		
		//score.SetPosition(scoreTitle.GetPosition().x + 50, scoreTitle.GetPosition().y);
	}

	void UpdateHealth()
	{
		if(m_shipHealth>=0)
		{
			s= _itoa(m_shipHealth, buffer, 10);
			health.SetText(s);
		}
	}

	void IncreaseScore(int s)
	{
		m_score+=s;
		
	}
	void DecreaseHealth()
	{
		m_shipHealth--;
	}
	int GetHealth()
	{
		return m_shipHealth;
	}
	Sprite GetSprite()
	{
		return m_shipSprite;
	}
	float GetSpeed()
	{
		return m_shipSpeed;
	}
	void SetSpeed(float f){m_shipSpeed = f;}
	bool IsDestroyed(){ return m_isDestroyed;}
	void MoveUp(float time);
	void MoveSide(float time);
	void Draw(RenderWindow *win);
	void Right();
	void Left();
	float GetCenterX(){return m_shipSprite.GetCenter().x;}
	float GetCenterY(){return m_shipSprite.GetCenter().y;}
	//void Simulate(float time, bool key, bool down);
	void AddForce(float x, float y);
	void Move(float x, float y);
	void AddVelocity(float x, float y);
	float GetPositionX();
	float GetPositionY();
	void Throttled();
	View GetView(){return m_view;}
	void NoThrottle();
	void UpdateAI();
	float GetSizeX()
	{
		return m_shipSprite.GetSize().x;
	}
	float GetSizeY()
	{
		return m_shipSprite.GetSize().y;
	}
	void TellDestroyed(){m_isDestroyed = true;m_shipHealth=0;}
	void Destroyed()
	{
		m_shipSprite.SetImage(m_shipImage4);
	//	m_shipSprite.SetCenter((float)m_shipImage0.GetWidth()/2, (float)m_shipImage0.GetHeight()/2);
		m_shipSprite.Resize((float)m_shipImage4.GetWidth(), (float)m_shipImage4.GetHeight());
	}
	StateManager<PlayerShip>* GetStateManager();
};
#endif