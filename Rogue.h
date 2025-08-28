#pragma once
#include "PlayerClass.h"
class Rogue : public PlayerClass
{
public:
	Rogue();


	int bonusMultiplier() const override;
	void setClassStats(Entity& entity) override;
};

