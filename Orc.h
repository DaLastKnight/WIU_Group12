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
	Orc();
	void spawnOrc(char difficultyGrade);
	~Orc();
};
