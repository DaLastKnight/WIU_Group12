#pragma once
#include "Enemy.h"
#include "Position.h"
#include <iostream>

class Wolflord : public Enemy
{
private:
	int row;
	int column;

public:
	Wolflord();
	void spawnWolfLord(char difficultyGrade); // auto passes difficulty multiplier 
	~Wolflord();
};

