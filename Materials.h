#pragma once

class Materials
{
private:
    int normalWoodAmount;
    int normalStoneAmount;
    int eliteWoodAmount;
    int eliteStoneAmount;
    int bossWoodAmount;
    int bossStoneAmount;
    int wood;
    int stone;

public:
    Materials(int normalWood, int normalStone, int eliteWood, int eliteStone, int bossWood, int bossStone);

    void generateRandomMaterials();
    void updateTotals();
    void displayMaterials() const;
};