#pragma once
#include "Equipments.h"
#include <string>

class Weapons : public Equipments
{
protected:
    int price;
    int baseAttack;
public:
    Weapons();

    void displayStats() const;

    int getPrice() const;
    int getBaseAttack() const;

    virtual void weaponSprite(int tier) = 0;
};