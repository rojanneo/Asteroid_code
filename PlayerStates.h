#ifndef PlayerShipSTATES_H_
#define PlayerShipSTATES_H_
#include "State.h"
//#include "PlayerShip.h"
class PlayerShip;

class IsAlive:public State<PlayerShip>
{
private:
	IsAlive(){}
	IsAlive& operator = (const IsAlive&);
public:
	static IsAlive* Instance();
	void Enter(PlayerShip *PlayerShip);
	void Execute(PlayerShip *PlayerShip);
	void Exit(PlayerShip *PlayerShip);
};

class IsDestroyed:public State<PlayerShip>
{
private:
	IsDestroyed(){}
	IsDestroyed& operator =(IsDestroyed&);
public:
	static IsDestroyed* Instance();
	void Enter(PlayerShip *PlayerShip);
	void Execute(PlayerShip *PlayerShip);
	void Exit(PlayerShip *PlayerShip);
};


#endif