#include "BulletStates.h"
#include "Bullet.h"
#include <iostream>
using namespace std;
HasNotHit* HasNotHit::Instance()
{
	static HasNotHit instance;
	return &instance;
}


void HasNotHit::Enter(Bullet* Bullet)
{
	
}

void HasNotHit::Execute(Bullet* Bullet)
{	
	if(Bullet->IsHit())
	{
		Bullet->GetStateManager()->ChangeState(HasHit::Instance());
	}
	
}

void HasNotHit::Exit(Bullet* Bullet)
{
}

HasHit* HasHit::Instance()
{
	static HasHit instance;
	return &instance;
}


void HasHit::Enter(Bullet *Bullet)
{
}

void HasHit::Execute(Bullet *Bullet)
{
	Bullet->Destroyed();
}

void HasHit::Exit(Bullet *Bullet)
{
	
}
