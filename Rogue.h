#pragma once
#include "PlayerClass.h"
class Rogue : public PlayerClass
{
public:
	Rogue();
	Rogue(int hp, int atk, int def, int spd) : PlayerClass() {};

	void skill(Entity& entity, int bonusVal) override;
	void setClassStats(Entity& entity) override;
};

