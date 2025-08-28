#pragma once
#include "Entity.h"
#include "PlayerClass.h"

class Player : public Entity
{
private:
	PlayerClass* specialty;

	char input;
	int bonusValue;

public:
	Player();
	// Player(int row, int col) : Entity(row, col, 'P', health, attack, defense, speed) {}

	void viewCurrentStats();
	void setClassStats(PlayerClass* playerclass);
	void useSkill(Entity* target);

	void attacking(Entity* target) override;
	void defending(Entity* target) override;

	void bonusVal(int amount);
	void resetVal();
};

