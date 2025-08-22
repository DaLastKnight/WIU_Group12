#pragma once
#include "PlayerClass.h"
class Warrior : public PlayerClass
{
public:
	Warrior();
	Warrior(int hp, int atk, int def, int spd) : PlayerClass() {};

	int bonusValue() const override;
	void skill(Entity& entity, int bonusVal) override;
	void setClassStats(Entity& entity) override;
};

