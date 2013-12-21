#ifndef BASEENTITY_H_
#define BASEENTITY_H_
#include "EntityNames.h"
#include <iostream>
class BaseEntity
{
private:
	int m_id;
	void SetID(int id)
	{
		m_id = id;
	}
public:
	BaseEntity(int id)
	{
		SetID(id);
	}
};
#endif