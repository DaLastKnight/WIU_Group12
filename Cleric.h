#pragma once
#include "PlayerClass.h"
class Cleric : public PlayerClass
{
public:
	Cleric();
	Cleric(int hp, int atk, int def, int spd) : PlayerClass() {};

	void skill(Entity& entity, int bonusVal) override;
	void setClassStats(Entity& entity) override;
};

