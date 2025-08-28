#pragma once
#include "Enemy.h"
#include "Position.h"
#include <iostream>

class Giantgoblin : public Enemy
{
private:
	int row;
	int column;

public:
	Giantgoblin(char difficultyGrade);
	~Giantgoblin();

	void attacking(Entity* target) override;

	void setEnemyGrade() override;
	char getEnemyGrade() override;
};