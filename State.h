#ifndef STATES_H_
#define STATES_H_
template<class BaseEntity>
class State
{
public:
	virtual void Enter(BaseEntity*) = 0;
	virtual void Execute(BaseEntity*) = 0;
	virtual void Exit(BaseEntity*) = 0;
};
#endif