#include "PlayerShip.h"
void PlayerShip::Draw(RenderWindow *win)
{
	m_shipSprite.SetPosition(m_shipPosition.x, m_shipPosition.y);
	win->Draw(m_shipSprite);
	win->Draw(score);
	win->Draw(scoreTitle);
	win->Draw(healthTitle);
	win->Draw(health);
	if(m_isDestroyed)
	{
		win->GetDefaultView();
		win->Draw(m_gameOver);
	}
}


void PlayerShip::MoveUp(float time)
{
//	m_shipPosition.y += (float)(m_shipVelocity.y * time );
	//m_shipPosition.x += m_shipVelocity.x * time + m_shipAcceleration.x * time *time * 0.5;
	if(!m_isDestroyed)
	{
		//m_shipSprite.Move(0, -m_shipSpeed*time);
		m_shipPosition.y -= m_shipSpeed * time;
		m_view.Move(0, -m_shipSpeed* time);
		score.Move(0, -m_shipSpeed * time);
		scoreTitle.Move(0, -m_shipSpeed * time);
		healthTitle.Move(0,-m_shipSpeed * time);
		health.Move(0, -m_shipSpeed * time);
	}
	else
	{
		m_gameOver.SetPosition(m_view.GetCenter().x, m_view.GetCenter().y);
	}
	//m_shipPosition.y += m_shipVelocity.y * time + m_shipAcceleration.y * time *time * 0.5;
	//m_shipPosition += m_shipVelocity * time + m_shipAcceleration*time*time*0.5;
	
}

void PlayerShip::MoveSide(float time)
{
	//m_shipPosition.x+=m_shipSpeed*time;
	m_shipPosition.x += (float)(m_shipVelocity.x * time + m_shipAcceleration.x*time*time*0.5);
	//m_shipSprite.Move(m_shipVelocity.x*time,0);
	
}


void PlayerShip::AddVelocity(float i, float j)
{
	m_shipVelocity.x = i;
	m_shipVelocity.y = j;
}

void PlayerShip::Move(float x, float y)
{
	//std::cout<<"MOVE";
	m_shipSprite.Move(x,y);
}
void PlayerShip::AddForce(float x, float y)
{
	m_shipForce.x = x;
	m_shipForce.y = y;
}
float PlayerShip::GetPositionX()
{
	return m_shipSprite.GetPosition().x;
}
float PlayerShip::GetPositionY()
{
	return m_shipSprite.GetPosition().y;
}
void PlayerShip::Throttled()
{
	m_shipSprite.SetImage(m_shipImage1);
	SetSpeed(300);
}
void PlayerShip::NoThrottle()
{
		m_shipSprite.SetImage(m_shipImage0);
		SetSpeed(100);
}
void PlayerShip::Right()
{
	m_shipSprite.SetImage(m_shipImage2);
}
void PlayerShip::Left()
{
	m_shipSprite.SetImage(m_shipImage3);
}
StateManager<PlayerShip>* PlayerShip::GetStateManager()
{
	return m_stateManager;
}
void PlayerShip::UpdateAI()
{
	m_stateManager->Update();
}