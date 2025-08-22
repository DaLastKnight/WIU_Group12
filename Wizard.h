#pragma once
#include "PlayerClass.h"
class Wizard : public PlayerClass
{
public:
	Wizard();
	Wizard(int hp, int atk, int def, int spd) : PlayerClass() {};

	void skill(Entity& entity, int bonusVal) override;
	void setClassStats(Entity& entity) override;
};

