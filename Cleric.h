#pragma once
#include "Player.h"
class Cleric : public Player
{
public:
	Cleric();
	Cleric(int hp, int atk, int def, int spd) : Player() {};

	void skill(int bonusVal) override;
	void setClassStats() override;
};

