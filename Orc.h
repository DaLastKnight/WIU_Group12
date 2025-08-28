#pragma once
#include "Enemy.h"
#include "Position.h"
#include <iostream>

class Orc : public Enemy
{
private:
	int row;
	int column;

public:
	Orc(char difficultyGrade);
	~Orc();

	void attacking(Entity* target) override;

	void setEnemyGrade() override;
	char getEnemyGrade() override;
};