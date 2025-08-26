#pragma once
#include "Entity.h"
#include "PlayerClass.h"

class Player : public Entity
{
private:
	PlayerClass* specialty;

	char input;

	bool confirmSelection();
public:
	Player();
	// Player(int row, int col) : Entity(row, col, 'P', health, attack, defense, speed) {}

	void viewCurrentStats();
	void setClassStats(PlayerClass* playerclass);
	void useSkill(PlayerClass* playerskill);

	void attacking() override;
	void defending();
};

