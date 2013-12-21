#ifndef BULLETSTATES_H_
#define BULLETSTATES_H_
#include "State.h"
class Bullet;

class HasNotHit:public State<Bullet>
{
private:
	HasNotHit(){}
	HasNotHit& operator = (const HasNotHit&);
public:
	static HasNotHit* Instance();
	void Enter(Bullet *bullet);
	void Execute(Bullet *bullet);
	void Exit(Bullet *bullet);
};

class HasHit:public State<Bullet>
{
private:
	HasHit(){}
	HasHit& operator =(HasHit&);
public:
	static HasHit* Instance();
	void Enter(Bullet *bullet);
	void Execute(Bullet *bullet);
	void Exit(Bullet *bullet);
};
#endif