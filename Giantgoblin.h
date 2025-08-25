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
	Giantgoblin();
	void spawnGiantgoblin(char difficultyGrade);
	~Giantgoblin();
};