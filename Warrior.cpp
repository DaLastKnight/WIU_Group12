#include <iostream>
#include "Warrior.h"

Warrior::Warrior()
{
}

int Warrior::bonusValue() const
{
    return 5;
}

void Warrior::skill(Entity& entity, int bonusVal)
{
    std::cout << "You have casted Aura Blade\n";
    int totalDamage = entity.getAttack() + bonusVal;
    std::cout << totalDamage;
}

void Warrior::setClassStats(Entity& entity)
{
    entity.setStats(100, 20, 8, 12);
}

