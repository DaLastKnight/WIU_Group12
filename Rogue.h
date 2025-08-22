#pragma once
#include "Player.h"
class Rogue : public Player
{
public:
	Rogue();
	Rogue(int hp, int atk, int def, int spd) : Player() {};

	void skill(int bonusVal) override;
	void setClassStats() override;
};

