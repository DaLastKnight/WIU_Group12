#pragma once
#include "PlayerClass.h"
class Rogue : public PlayerClass
{
public:
	Rogue();
	Rogue(int hp, int atk, int def, int spd) : PlayerClass() {};

	int bonusValue() const override;
	void skill(Entity& entity, int bonusVal) override;
	void setClassStats(Entity& entity) override;
};

