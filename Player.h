#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
	char input;

	bool confirmSelection();
public:
	Player();
	Player(int row, int col) : Entity(row, col, 'P', health, attack, defense, speed) {}

	void viewCurrentStats();
	void useSkill();

	void attacking() override;
	void defending();

	void move(char table[20][20]);

	virtual void skill(int bonusVal) = 0;
	virtual void setClassStats() = 0;
};

