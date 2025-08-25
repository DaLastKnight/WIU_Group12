#include "Orc.h"
#include "Entity.h"
#include "Position.h"

Orc::Orc() : Enemy(row, column, 'O', 29, 8, 4, 7, 'E')
{

}

void Orc::spawnOrc(char difficultyGrade)
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

    std::cout << "You have encountered an Orc:" << std::endl;
    std::cout << "HP: " << getHealth() << ", ATK: " << getAttack()
        << ", DEF: " << getDefense() << ", SPD: " << getSpeed() << std::endl;
}

Orc::~Orc()
{
    std::cout << "Orc has been killed" << std::endl;
}