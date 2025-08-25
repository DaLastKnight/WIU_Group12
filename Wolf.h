#pragma once
#include "Enemy.h"
#include "Position.h"
#include <iostream>

class Wolf : public Enemy 
{
private:
	int row;
	int column;

public:
	Wolf();
	void spawnWolf(char difficultyGrade);
	~Wolf();
};
