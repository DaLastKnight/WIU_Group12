#include "Alphawolf.h"
#include "Entity.h"
#include "Position.h"

Alphawolf::Alphawolf() : Enemy(row, column, 'A', 25, 7, 2, 12, 'E')
{

}

void Alphawolf::spawnAlphaWolf(char difficultyGrade)
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

    std::cout << "You have encountered an Alpha wolf:" << std::endl;
    std::cout << "HP: " << getHealth() << ", ATK: " << getAttack()
    << ", DEF: " << getDefense() << ", SPD: " << getSpeed() << std::endl;
}

Alphawolf::~Alphawolf()
{
    std::cout << "Alpha wolf has been killed" << std::endl;
}