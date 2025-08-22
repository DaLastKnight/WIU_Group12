#include <iostream>
#include "Warrior.h"

Warrior::Warrior()
{
}

void Warrior::skill(Entity& entity, int bonusVal)
{
    std::cout << "You have casted Aura Blade\n";
    int totalDamage = entity.getAttack() + bonusVal;
}

void Warrior::setClassStats(Entity& entity)
{
    entity.setStats(100, 20, 8, 12);
}

