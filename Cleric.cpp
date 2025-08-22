#include <iostream>
#include "Cleric.h"

Cleric::Cleric()
{
    setClassStats();
}

void Cleric::skill(int bonusVal)
{
    std::cout << "You have casted Heal\n";
    setStats(getHealth() + bonusVal, 15, 2, 10);
}

void Cleric::setClassStats()
{
    setStats(65, 15, 2, 10);
}
