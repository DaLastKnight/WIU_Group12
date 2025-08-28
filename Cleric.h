#pragma once
#include "PlayerClass.h"
class Cleric : public PlayerClass
{
public:
	Cleric();


	int bonusMultiplier() const override;
	void setClassStats(Entity& entity) override;
};

