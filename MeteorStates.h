#ifndef METEORSTATES_H_
#define METEORSTATES_H_
#include "State.h"
class Meteor;
class MeteorHasNotHit:public State<Meteor>
{
private:
	MeteorHasNotHit(){}
	MeteorHasNotHit& operator = (const MeteorHasNotHit&);
public:
	static MeteorHasNotHit* Instance();
	void Enter(Meteor *Meteor);
	void Execute(Meteor *Meteor);
	void Exit(Meteor *Meteor);
};


class MeteorHasHit:public State<Meteor>
{
private:
	MeteorHasHit(){}
	MeteorHasHit& operator =(MeteorHasHit&);
public:
	static MeteorHasHit* Instance();
	void Enter(Meteor *Meteor);
	void Execute(Meteor *Meteor);
	void Exit(Meteor *Meteor);
};
#endif