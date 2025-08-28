#pragma once
#include "Enemy.h"
#include "Position.h"
#include <iostream>

class Wolf : public Enemy 
{
private:
	int row;
	int col; 

public:
	Wolf(char difficultyGrade);
	~Wolf();

	void attacking(Entity* target) override;

	void setEnemyGrade() override;
	char getEnemyGrade() override;
};
