#pragma once
#include "Enemy.h"
#include "Position.h"
#include <iostream>
class Goblin : public Enemy
{
private:
	int row;
	int column;

public:
	Goblin(char difficultyGrade);
	~Goblin();

	void attacking(Entity* target) override;

	void setEnemyGrade() override;
	char getEnemyGrade() override;
};