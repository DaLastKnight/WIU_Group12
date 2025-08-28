#pragma once
#include "Equipments.h" // For Equipments array
#include "Items.h"      // For Items array
#include "Wood.h"
#include "Stone.h"
#include <string>
#include <iostream>
#include <cctype>       // For character manipulation (tolower)

class Game;

// Manages the player's inventory, separating equipments and general items.
class Inventory
{
public:
    // Constructor with customizable capacities for equipment and general items.
    Inventory(size_t equipmentCapacity = 5, size_t itemCapacity = 100000, Game* gamePtr = nullptr);
    // Destructor to free dynamically allocated memory.
    ~Inventory();

    Wood* getWoodPtr() const;
    Stone* getStonePtr() const;
    

    // Opens the main inventory menu.
    void openInventory();
    // Adds an equipment item to the equipment inventory.
    void addEquipment(Equipments* equipment);
    // Adds a general item to the general items inventory.
    void addItem(Items* item);

    // Helper function to convert a character to ASCII lowercase.
    static int asciiToLower(int c);

    // Helper function to compare two strings ignoring ASCII case.
    bool equalsIgnoreCaseASCII(const std::string& str1, const std::string& str2) const;

    // get Equipment Inventory Sizes
    int getCurrentEquipmentSize() const;
    int getMaxEquipmentSize() const;
   
private:
    int placeholderInt;
    bool inventoryOpened;
    bool* isEquipmentEquipped;

    Game* gamePtr;
    Wood* woodPtr;
    Stone* stonePtr;

    Equipments** equipments; // Array to store pointers to Equipments.
    size_t currentEquipmentSize;    // Current number of equipments.
    size_t maxEquipmentCapacity;    // Maximum capacity for equipments.

    Items** generalItems;   // Array to store pointers to general Items.
    size_t currentItemSize;     // Current number of general items.
    size_t maxItemCapacity;     // Maximum capacity for general items.

    // Finds the actual index of an equipment pointer in the equipments array.
    size_t findEquipmentIndex(Equipments* eqPtr) const;
    // Finds the actual index of an item pointer in the generalItems array.
    size_t findItemIndex(Items* itemPtr) const;

    // Removes an equipment at a specific index and returns the pointer.
    Equipments* removeEquipment(size_t index);
    // Removes a general item at a specific index and returns the pointer.
    Items* removeGeneralItem(size_t index);

    // Handlers for the main sections of the inventory (Equipments, Items).
	Equipments* equippedWeapon = nullptr;
	Equipments* equippedArmor = nullptr;
    bool handleEquipmentSection();
    bool handleItemSection();

    // Handlers for specific item categories within Equipment or General Items.
    bool handleEquipmentCategoryItems(const std::string& selectedCategory);
    bool handleItemCategoryItems(const std::string& selectedCategory);

    // Handlers for displaying details and performing actions on a selected item.
    bool handleEquipmentDetailsAndActions(const std::string& selectedCategory, Equipments* selectedEquipmentPtr, size_t actualIndex);
    bool handleItemDetailsAndActions(const std::string& selectedCategory, Items* selectedItemPtr, size_t actualIndex);

    // Getters to retrieve filtered lists of items by type/category.
    int getEquipmentsByType(const std::string& category, Equipments** outputArray, size_t maxOutputCount) const;
    int getItemsByType(const std::string& category, Items** outputArray, size_t maxOutputCount) const;

    // Actions that can be performed on inventory items.
    std::string equipEquipmentAction(Equipments* equipment);
    std::string unequipEquipmentAction(Equipments* equipment);
    bool trashEquipmentAction(Equipments* equipment, size_t actualIndex);
    bool trashItemAction(Items* item, size_t actualIndex);
    std::string useItemAction(Items* item, size_t actualIndex);
};