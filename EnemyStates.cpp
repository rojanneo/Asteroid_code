#include "EnemyStates.h"
#include "EnemyShip.h"
HasHitEnemy* HasHitEnemy::Instance()
{
	static HasHitEnemy instance;
	return &instance;
}


void HasHitEnemy::Enter(EnemyShip *EnemyShip)
{
}

void HasHitEnemy::Execute(EnemyShip *EnemyShip)
{
	//std::cout<<"D";
	EnemyShip->DestroyedImage();
}
void HasHitEnemy::Exit(EnemyShip *EnemyShip)
{
}

Attack* Attack::Instance()
{
	static Attack instance;
	return &instance;
}


void Attack::Enter(EnemyShip *EnemyShip)
{
}

void Attack::Execute(EnemyShip *EnemyShip)
{
	
	if(EnemyShip->GetHealth()<=3)
	{
		EnemyShip->GetStateManager()->ChangeState(LowHealthEnemy::Instance());
	}
	else
	{
		EnemyShip->Attack();
	}
}
void Attack::Exit(EnemyShip *EnemyShip)
{
}

LowHealthEnemy* LowHealthEnemy::Instance()
{
	static LowHealthEnemy instance;
	return &instance;
}


void LowHealthEnemy::Enter(EnemyShip *EnemyShip)
{
}

void LowHealthEnemy::Execute(EnemyShip *EnemyShip)
{
	//std::cout<<"LowHealth";
	EnemyShip->HealthImage();
	if(EnemyShip->IsDestroyed())
	{
		EnemyShip->GetStateManager()->ChangeState(HasHitEnemy::Instance());
	}

}
void LowHealthEnemy::Exit(EnemyShip *EnemyShip)
{
}



NotHit* NotHit::Instance()
{
	static NotHit instance;
	return &instance;
}


void NotHit::Enter(EnemyShip *EnemyShip)
{
}

void NotHit::Execute(EnemyShip *EnemyShip)
{
	//cout<<"MeteorHasNotHit";
	
	
	if(EnemyShip->GetHealth()<= 3)
	{
		EnemyShip->GetStateManager()->ChangeState(LowHealthEnemy::Instance());
	}
	else if(EnemyShip->IsAttacking())
	{
		EnemyShip->GetStateManager()->ChangeState(Attack::Instance());
	}
}

void NotHit::Exit(EnemyShip *EnemyShip)
{
	
}
