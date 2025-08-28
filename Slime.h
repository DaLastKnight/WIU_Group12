#pragma once
#include "Enemy.h"
#include "Position.h"
#include <iostream>
class Slime : public Enemy
{
private:
	int row;
	int column;

public:
	Slime(char difficultyGrade);
	~Slime();

	void attacking(Entity* target) override;

	void setEnemyGrade() override;
	char getEnemyGrade() override;
};