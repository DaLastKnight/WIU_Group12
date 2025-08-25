#pragma once
#include "Enemy.h"
#include "Position.h"
#include <iostream>

class Alphawolf: public Enemy
{
private:
	int row;
	int column;

public:
	Alphawolf();
	void spawnAlphaWolf(char difficultyGrade);
	~Alphawolf();
};
