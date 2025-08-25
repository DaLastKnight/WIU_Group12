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
	Slime();
	void spawnSlime(char difficultyGrade);
	~Slime();
};