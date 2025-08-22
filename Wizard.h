#pragma once
#include "Player.h"
class Wizard : public Player
{
public:
	Wizard();
	Wizard(int hp, int atk, int def, int spd) : Player() {};

	void skill(int bonusVal) override;
	void setClassStats() override;
};

