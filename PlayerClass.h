#include "Entity.h"

#pragma once
class PlayerClass
{
public:
	virtual int bonusValue() const = 0;
	virtual void skill(Entity& entity, int bonusVal) = 0;
	virtual void setClassStats(Entity& entity) = 0;
	virtual ~PlayerClass() = default;
};

