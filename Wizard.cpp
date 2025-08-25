#include <iostream>
#include "Wizard.h"

Wizard::Wizard()
{
}

int Wizard::bonusValue() const
{
    return 4;
}

void Wizard::skill(Entity& entity, int bonusVal)
{
    std::cout << "You have casted Greater Fireball\n";
    int totalDamage = entity.getAttack() + bonusVal;
}

void Wizard::setClassStats(Entity& entity)
{
    entity.setStats(75, 25, 4, 9);
}
