#include <iostream>
#include "Cleric.h"

Cleric::Cleric()
{
}

int Cleric::bonusValue() const
{
    return 15;
}

void Cleric::skill(Entity& entity, int bonusVal)
{
    std::cout << "You have casted Heal\n";
    entity.setStats(entity.getHealth() + bonusVal, 15, 2, 10);
}

void Cleric::setClassStats(Entity& entity)
{
    entity.setStats(85, 15, 6, 10);
}
