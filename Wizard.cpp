#include <iostream>
#include "Wizard.h"

Wizard::Wizard()
{
    setClassStats();
}

void Wizard::skill(int bonusVal)
{
    std::cout << "You have casted Greater Fireball\n";
    int totalDamage = getAttack() + bonusVal;
}

void Wizard::setClassStats()
{
    setStats(50, 35, 2, 7);
}
