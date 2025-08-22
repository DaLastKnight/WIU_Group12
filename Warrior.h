#pragma once
#include "Player.h"
class Warrior : public Player
{
public:
	Warrior();
	Warrior(int hp, int atk, int def, int spd) : Player() {};

	void skill(int bonusVal) override;
	void setClassStats() override;
};

