#include "MeteorStates.h"
#include "Meteor.h"

MeteorHasHit* MeteorHasHit::Instance()
{
	static MeteorHasHit instance;
	return &instance;
}


void MeteorHasHit::Enter(Meteor *Meteor)
{
}

void MeteorHasHit::Execute(Meteor *Meteor)
{
	//<<"HIt";
	Meteor->Destroyed();
}

void MeteorHasHit::Exit(Meteor *Meteor)
{
	
}

MeteorHasNotHit* MeteorHasNotHit::Instance()
{
	static MeteorHasNotHit instance;
	return &instance;
}


void MeteorHasNotHit::Enter(Meteor *Meteor)
{
}

void MeteorHasNotHit::Execute(Meteor *Meteor)
{
	//cout<<"MeteorHasNotHit";
	if(Meteor->IsDestroyed())
	{
		Meteor->GetStateManager()->ChangeState(MeteorHasHit::Instance());
	}
}

void MeteorHasNotHit::Exit(Meteor *Meteor)
{
	
}
