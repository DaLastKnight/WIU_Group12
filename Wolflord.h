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
    Wolflord(char difficultyGrade);
    ~Wolflord();

    void attacking(Entity* target) override;

    void setEnemyGrade() override;
    char getEnemyGrade() override;
};

