#pragma once
#include "Equipments.h"
#include <string>

class Armor : public Equipments
{
protected:
    int price;
    int def;
    int hp;
    int spd;
public:
    Armor();

    // For Inventory
    void displayStats() const;
    int getPrice() const;

    virtual void armorSprite(int tier) = 0;
};
