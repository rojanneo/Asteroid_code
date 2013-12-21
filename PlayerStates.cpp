#include "PlayerShip.h"
#include "PlayerStates.h"
#include <iostream>
using namespace std;
IsAlive* IsAlive::Instance()
{
	static IsAlive instance;
	return &instance;
}


void IsAlive::Enter(PlayerShip* PlayerShip)
{
	

}

void IsAlive::Execute(PlayerShip* PlayerShip)
{	
	if(PlayerShip->IsDestroyed())
	{
		PlayerShip->GetStateManager()->ChangeState(IsDestroyed::Instance());
	}
	
}

void IsAlive::Exit(PlayerShip* PlayerShip)
{
	
}

IsDestroyed* IsDestroyed::Instance()
{
	static IsDestroyed instance;
	return &instance;
}


void IsDestroyed::Enter(PlayerShip *PlayerShip)
{
}

void IsDestroyed::Execute(PlayerShip *PlayerShip)
{
	PlayerShip->Destroyed(); 
}

void IsDestroyed::Exit(PlayerShip *PlayerShip)
{
	
}

