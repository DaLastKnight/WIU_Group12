#pragma once
#include "Enemy.h"
#include "Position.h"
#include <iostream>

class Alphawolf : public Enemy
{
private:
	int row;
	int column;

public:
	Alphawolf(char difficultyGrade);
	~Alphawolf();

	void attacking(Entity* target) override;

	void setEnemyGrade() override;
	char getEnemyGrade() override;
};
