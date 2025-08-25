#include "Wolflord.h"
#include "Entity.h"
#include "Position.h"

Wolflord::Wolflord() : Enemy(row, column, 'W', 28, 7, 4, 9, 'B')
{

}

void Wolflord::spawnWolfLord(char difficultyGrade)
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

    std::cout << "You have encountered an Wolflord:" << std::endl;
    std::cout << "HP: " << getHealth() << ", ATK: " << getAttack()
    << ", DEF: " << getDefense() << ", SPD: " << getSpeed() << std::endl;
}

Wolflord::~Wolflord()
{
    std::cout << "Wolflord has been killed" << std::endl;
}
