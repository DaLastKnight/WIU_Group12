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
	Goblin();
	void spawnGoblin(char difficultyGrade);
	~Goblin();
};