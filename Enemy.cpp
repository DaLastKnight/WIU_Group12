#include "Enemy.h"
#include "Entity.h"
#include "Position.h"

void Enemy::applyGradeMultiplier()
{
    if (grade == 'N')
    {
        health *= 1.0;
        attack *= 1.0;
        defense *= 1.0;
        speed *= 1.0;
    }
    if (grade == 'E')
    {
        health *= 1.5;
        attack *= 1.5;
        defense *= 1.5;
        speed *= 1.5;
    }
    if (grade == 'B')
    {
        health *= 3.0;
        attack *= 3.0;
        defense *= 3.0;
        speed *= 3.0;
    }
}

Enemy::Enemy(int row, int col, char symbol, int hp, int atk, int def, int spd, char g) : Entity(row, col, symbol, hp, atk, def, spd), grade(g) // Set grade for derived classes
{
    applyGradeMultiplier();
}

Enemy::Enemy() {}
Enemy::Enemy(int row, int col, char symbol) : Entity(row, col, symbol, 0, 0, 0, 0), grade('U') {}
