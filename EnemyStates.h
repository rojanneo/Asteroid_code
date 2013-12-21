#ifndef EnemyShipSTATES_H_
#define EnemyShipSTATES_H_
#include "State.h"
class EnemyShip;
class NotHit:public State<EnemyShip>
{
private:
	NotHit(){}
	NotHit& operator = (const NotHit&);
public:
	static NotHit* Instance();
	void Enter(EnemyShip *EnemyShip);
	void Execute(EnemyShip *EnemyShip);
	void Exit(EnemyShip *EnemyShip);
};


class HasHitEnemy:public State<EnemyShip>
{
private:
	HasHitEnemy(){}
	HasHitEnemy& operator =(HasHitEnemy&);
public:
	static HasHitEnemy* Instance();
	void Enter(EnemyShip *EnemyShip);
	void Execute(EnemyShip *EnemyShip);
	void Exit(EnemyShip *EnemyShip);
};

class Attack:public State<EnemyShip>
{
private:
	Attack(){}
	Attack& operator =(Attack&);
public:
	static Attack* Instance();
	void Enter(EnemyShip *EnemyShip);
	void Execute(EnemyShip *EnemyShip);
	void Exit(EnemyShip *EnemyShip);
};

class LowHealthEnemy:public State<EnemyShip>
{
private:
	LowHealthEnemy(){}
	LowHealthEnemy& operator =(LowHealthEnemy&);
public:
	static LowHealthEnemy* Instance();
	void Enter(EnemyShip *EnemyShip);
	void Execute(EnemyShip *EnemyShip);
	void Exit(EnemyShip *EnemyShip);
};

#endif