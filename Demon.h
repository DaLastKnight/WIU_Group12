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
	Demon();
	void spawnDemon(char difficultyGrade); // auto passes difficulty multiplier 
	~Demon();
};