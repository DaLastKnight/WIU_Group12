#include <iostream>
#include "Rogue.h"

Rogue::Rogue()
{
}

void Rogue::skill(Entity& entity, int bonusVal)
{
    std::cout << "You have casted Quick Blade\n";
    int totalDamage = entity.getAttack() + bonusVal;
}

void Rogue::setClassStats(Entity& entity)
{
    entity.setStats(90, 18, 6, 16);
}
