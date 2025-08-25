#pragma once
#include "Equipments.h"
#include <string>

class Weapons : public Equipments
{
protected:
    std::string name;
    int price;
    int baseAttack;
    int tier;
public:
    Weapons();

    std::string getName() const;
    int getPrice() const;
    int getBaseAttack() const;
    int getTier() const;
};