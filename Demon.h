#pragma once
#include "Enemy.h"
#include "Position.h"
#include <iostream>

class Demon : public Enemy
{
private:
	int row;
	int column;

public:
	Demon(char difficultyGrade);
	~Demon();

	void attacking(Entity* target) override;

	void setEnemyGrade() override;
	char getEnemyGrade() override;
};