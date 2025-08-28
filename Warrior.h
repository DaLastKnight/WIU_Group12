#pragma once
#include "PlayerClass.h"
class Warrior : public PlayerClass
{
public:
	Warrior();

	int bonusMultiplier() const override;
	void setClassStats(Entity& entity) override;
};

