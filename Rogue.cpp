#include <iostream>
#include "Rogue.h"

Rogue::Rogue()
{
    setClassStats();
}

void Rogue::skill(int bonusVal)
{
    std::cout << "You have casted Quick Blade\n";
    int totalDamage = getAttack() + bonusVal;
}

void Rogue::setClassStats()
{
    setStats(80, 20, 3, 15);
}
