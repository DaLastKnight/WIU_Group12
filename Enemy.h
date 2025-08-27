#pragma once
#include "Entity.h"
#include "Position.h"

class Enemy : public Entity
{
protected:
    char grade;
    int row;
    int col;

    void applyGradeMultiplier();


    Enemy(int row, int col, char symbol, int hp, int atk, int def, int spd, char g); // Set grade for derived classes

public:
    Enemy();
    Enemy(int row, int col, char symbol);

    char getGrade() const;
};

