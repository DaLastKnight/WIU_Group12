#pragma once
#include "Equipments.h"
#include <string>

class Armor: public Equipments
{
protected:
    std::string armorName;
    int tier;
    int price;
    int def;
    int hp;
    int spd;
public:
    Armor();
    // For Inventory
    std::string getName() const override { return armorName; }
    std::string getType() const override { return "ARMOR"; }
    void displayStats() const;
};
