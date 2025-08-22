#include <iostream>
#include "Warrior.h"

Warrior::Warrior()
{
    setClassStats();
}

void Warrior::skill(int bonusVal)
{
    std::cout << "You have casted Aura Blade\n";
    int totalDamage = getAttack() + bonusVal;
}

void Warrior::setClassStats()
{
    setStats(150, 25, 5, 12);
}

