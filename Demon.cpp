#include "Demon.h"
#include "Entity.h"
#include "Position.h"

Demon::Demon() : Enemy(row, column, 'D', 32, 8, 5, 5, 'B')
{

}

void Demon::spawnDemon(char difficultyGrade)
{
    if (difficultyGrade == 'E') // Easy
    {
        setStats(getHealth() * 0.8, getAttack() * 0.8, getDefense() * 0.8, getSpeed() * 0.8);
    }
    else if (difficultyGrade == 'N') // Normal
    {
        // Stats remain the same, so no action needed.
    }
    else if (difficultyGrade == 'H') // Hard
    {
        setStats(getHealth() * 1.2, getAttack() * 1.2, getDefense() * 1.2, getSpeed() * 1.2);
    }
    else if (difficultyGrade == 'O') // Oblivion
    {
        setStats(getHealth() * 1.4, getAttack() * 1.4, getDefense() * 1.4, getSpeed() * 1.4);
    }

    std::cout << "You have encountered an Demon:" << std::endl;
    std::cout << "HP: " << getHealth() << ", ATK: " << getAttack()
        << ", DEF: " << getDefense() << ", SPD: " << getSpeed() << std::endl;
}

Demon::~Demon()
{
    std::cout << "Demon has been killed" << std::endl;
}
