#pragma once
#include "PlayerClass.h"
class Wizard : public PlayerClass
{
public:
	Wizard();

	int bonusMultiplier() const override;
	void setClassStats(Entity& entity) override;
};

