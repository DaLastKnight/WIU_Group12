#pragma once
#include "Entity.h"
#include "Position.h"
#include <string>

class Enemy : public Entity
{
protected:
    char grade;
    char enemyType;
    int row;
    int col;

    void applyGradeMultiplier();


    Enemy(int row, int col, char symbol, int hp, int atk, int def, int spd, char g); // Set grade for derived classes

public:
    Enemy();
    Enemy(int row, int col, char symbol);

    virtual void setEnemyGrade() {};
    virtual char getEnemyGrade() { return grade; };
};

