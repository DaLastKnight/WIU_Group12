#include "Inventory.h"
#include "Game.h"
#include "Equipments.h"
#include "Weapons.h"
#include "Sword.h"
#include "Bow.h"
#include "Dagger.h"
#include "Items.h"
#include "Potions.h"
#include <iostream>
#include <string>
#include <conio.h> // _getch()
#include <cstdlib> // system("cls")
#include <cctype> // asciiToLower

// Constructor for the Inventory class.
// Initializes equipment and general item arrays with specified capacities.
Inventory::Inventory(size_t equipmentCapacity, size_t itemCapacity, Game* ptrToGame)
    : currentEquipmentSize(0), maxEquipmentCapacity(equipmentCapacity),
    currentItemSize(0), maxItemCapacity(itemCapacity), placeholderInt(0)
{
    // Allocate memory for equipment pointers and initialize to nullptr.
    equipments = new Equipments * [maxEquipmentCapacity];
    for (size_t i = 0; i < maxEquipmentCapacity; ++i) {
        equipments[i] = nullptr;
    }

    isEquipmentEquipped = new bool[maxEquipmentCapacity];

    for (int i = 0; i < maxEquipmentCapacity; i++)
    {
        isEquipmentEquipped[i] = false;
    }

	// Allocate memory for general item pointers and initialize to nullptr.
	generalItems = new Items * [maxItemCapacity];
	for (size_t i = 0; i < maxItemCapacity; ++i) {
		generalItems[i] = nullptr;
	}

    this->gamePtr = ptrToGame;
    woodPtr = new Wood(0);
    stonePtr = new Stone(0);
	addItem(woodPtr);
	addItem(stonePtr);
    //inventoryOpened = false;
}

// Destructor for the Inventory class.
// Deallocates all dynamically created equipment and item objects, then their arrays.
Inventory::~Inventory() {
    // Delete all equipment objects and then the equipment array.
    for (size_t i = 0; i < currentEquipmentSize; ++i) {
        if (equipments[i] != nullptr) {
            delete equipments[i];
        }
    }
    delete[] equipments;

    delete[] isEquipmentEquipped;

    // Delete all general item objects and then the general items array.
    for (size_t i = 0; i < currentItemSize; ++i) {
        if (generalItems[i] != nullptr) {
            delete generalItems[i];
        }
    }
    delete[] generalItems;
}

Wood* Inventory::getWoodPtr() const
{
    return woodPtr;
}

Stone* Inventory::getStonePtr() const
{
    return stonePtr;
}

// Adds an equipment item to the inventory.
// If inventory is full, the item is deleted.
void Inventory::addEquipment(Equipments* equipment) {
    if (currentEquipmentSize < maxEquipmentCapacity) {
        equipments[currentEquipmentSize++] = equipment;
    }
    else {
        delete equipment; // Delete item if it cannot be added.
    }
}

// Adds a general item to the inventory.
// If inventory is full, the item is deleted.
void Inventory::addItem(Items* item) {
    if (currentItemSize < maxItemCapacity) {
        generalItems[currentItemSize++] = item;
    }
    else {
        delete item; // Delete item if it cannot be added.
    }
}

// Finds the index of a given equipment pointer in the `equipments` array.
// Returns (size_t)-1 if not found.
size_t Inventory::findEquipmentIndex(Equipments* eqPtr) const {
    for (size_t i = 0; i < currentEquipmentSize; ++i) {
        if (equipments[i] == eqPtr) {
            return i;
        }
    }
    return (size_t)-1;
}

// Finds the index of a given item pointer in the `generalItems` array.
// Returns (size_t)-1 if not found.
size_t Inventory::findItemIndex(Items* itemPtr) const {
    for (size_t i = 0; i < currentItemSize; ++i) {
        if (generalItems[i] == itemPtr) {
            return i;
        }
    }
    return (size_t)-1;
}

// Removes an equipment from the array at the specified index.
// Shifts subsequent elements to fill the gap. Returns the removed equipment pointer.
Equipments* Inventory::removeEquipment(size_t index) {
    if (index >= currentEquipmentSize) {
        return nullptr; // Invalid index.
    }
    Equipments* removedEq = equipments[index];
    // Shift elements to the left.
    for (size_t i = index; i < currentEquipmentSize - 1; ++i) {
        equipments[i] = equipments[i + 1];
    }
    equipments[currentEquipmentSize - 1] = nullptr; // Clear the last element.
    currentEquipmentSize--; // Decrease size.
    return removedEq;
}

// Removes a general item from the array at the specified index.
// Shifts subsequent elements to fill the gap. Returns the removed item pointer.
Items* Inventory::removeGeneralItem(size_t index) {
    if (index >= currentItemSize) {
        return nullptr; // Invalid index.
    }
    Items* removedItem = generalItems[index];
    // Shift elements to the left.
    for (size_t i = index; i < currentItemSize - 1; ++i) {
        generalItems[i] = generalItems[i + 1];
    }
    generalItems[currentItemSize - 1] = nullptr; // Clear the last element.
    currentItemSize--; // Decrease size.
    return removedItem;
}

// Retrieves all equipments of a specific `category` (type) into `outputArray`.
// Returns the count of items found.
int Inventory::getEquipmentsByType(const std::string& category, Equipments** outputArray, size_t maxOutputCount) const {
	int count = 0;
	for (size_t i = 0; i < currentEquipmentSize; ++i) {
		if (count >= maxOutputCount) break; // Prevent buffer overflow.
		if (equipments[i] != nullptr && equalsIgnoreCaseASCII(equipments[i]->getType(), category)) {
			outputArray[count++] = equipments[i];
		}
	}
	return count;
}

// Retrieves all general items of a specific `category` (type) into `outputArray`.
// Returns the count of items found.
int Inventory::getItemsByType(const std::string& category, Items** outputArray, size_t maxOutputCount) const {
    int count = 0;
    for (size_t i = 0; i < currentItemSize; ++i) {
        if (count >= maxOutputCount) break; // Prevent buffer overflow.
        if (equalsIgnoreCaseASCII(generalItems[i]->getType(), category)) {
            outputArray[count++] = generalItems[i];
        }
    }
    return count;
}

// Placeholder action for equipping an equipment.
std::string Inventory::equipEquipmentAction(Equipments* equipment) {
	// Get the type of the equipment to determine the slot.
	std::string itemType = equipment->getType(); // Assumes you have a getType() method.
	size_t itemIndex = findEquipmentIndex(equipment);
	// Handle equipping a WEAPON.
	 // Handle equipping a WEAPON.
	if (itemType == "WEAPON") {
		if (equippedWeapon != nullptr) {
			// Find old weapon's index and mark it as unequipped.
			size_t oldWeaponIndex = findEquipmentIndex(equippedWeapon);
			if (oldWeaponIndex != (size_t)-1) {
				isEquipmentEquipped[oldWeaponIndex] = false;
			}
		}
		equippedWeapon = equipment;
		isEquipmentEquipped[itemIndex] = true; // Mark the new item as equipped.
        gamePtr->getPlayerPtr()->equipEquipment(equippedWeapon);
	}
	// Handle equipping ARMOR.
	else if (itemType == "ARMOR") {
		if (equippedArmor != nullptr) {
			// Find old armor's index and mark it as unequipped.
			size_t oldArmorIndex = findEquipmentIndex(equippedArmor);
			if (oldArmorIndex != (size_t)-1) {
				isEquipmentEquipped[oldArmorIndex] = false;
			}
		}
		equippedArmor = equipment;
		isEquipmentEquipped[itemIndex] = true; // Mark the new item as equipped.
		gamePtr->getPlayerPtr()->equipEquipment(equippedArmor);
	}
	return "You equipped " + equipment->getName() + "!\n";
}

// Placeholder action for unequipping an equipment.
std::string Inventory::unequipEquipmentAction(Equipments* equipment) {
	// Find the item's index in the main inventory array.
	size_t itemIndex = findEquipmentIndex(equipment);

	if (equipment == equippedWeapon) {
        isEquipmentEquipped[itemIndex] = false;
        equippedWeapon = nullptr;
		gamePtr->getPlayerPtr()->unequipEquipment(equipment);
    }
	else if (equipment == equippedArmor) {
		isEquipmentEquipped[itemIndex] = false;
		equippedArmor = nullptr;
		gamePtr->getPlayerPtr()->unequipEquipment(equipment);
    }
    return "You unequipped " + equipment->getName() + ".\n";
}

// Action to trash (delete) an equipment item.
// Returns true if successfully trashed, false otherwise.   
bool Inventory::trashEquipmentAction(Equipments* equipment, size_t actualIndex) {
    Equipments* removed = removeEquipment(actualIndex);
    if (removed != nullptr) {
        delete removed; // Free memory of the trashed item.
        return true;
    }
    return false;
}

// Action to trash (delete) a general item.
// Returns true if successfully trashed, false otherwise.
bool Inventory::trashItemAction(Items* item, size_t actualIndex) {
    Items* removed = removeGeneralItem(actualIndex);
    if (removed != nullptr) {
        delete removed; // Free memory of the trashed item.
        return true;
    }
    return false;
}

// Action to use a general item.
// Handles specific logic for potions (consumption).
bool Inventory::useItemAction(Items* item, size_t actualIndex) {
	if (item == nullptr) {
		return false;
	}

	// Check for consumables (Potions, etc.) and trash them.
	if (equalsIgnoreCaseASCII(item->getType(), "POTION") || equalsIgnoreCaseASCII(item->getType(), "MISCELLANEOUS")) {
		if (trashItemAction(item, actualIndex)) {
			// Item was successfully trashed/consumed.
			return true;
		}
		else {
			// Failed to trash item.
			return false;
		}
	}

	// For non-consumable items, assume they are used and exit.
	return true;
}

int Inventory::asciiToLower(int c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

bool Inventory::equalsIgnoreCaseASCII(const std::string& str1, const std::string& str2) const
{
    if (str1.length() != str2.length()) {
        return false;
    }
    for (size_t i = 0; i < str1.length(); ++i) {
        if (asciiToLower(str1[i]) != asciiToLower(str2[i])) {
            return false;
        }
    }
    return true;
}

int Inventory::getCurrentEquipmentSize() const
{
	int currentCapacity = static_cast<int>(currentEquipmentSize);
	return currentCapacity;
}

int Inventory::getMaxEquipmentSize() const
{
	int maxCapacity = static_cast<int>(maxEquipmentCapacity);
	return maxCapacity;
}

// Handles the detailed view and actions for a selected equipment.
// Returns true if the inventory should be closed entirely, false to return to previous menu.
bool Inventory::handleEquipmentDetailsAndActions(const std::string& selectedCategory, Equipments* selectedEquipmentPtr, size_t actualIndex) {
    int actionSelection = 0;
    const int numActions = 3;
    const std::string actions[] = { "Equip", "Unequip", "Trash/Delete" };
    std::string actionMessage = "";
    bool itemWasRemovedLocal = false;
    // Capture the item's name before potential deletion to use in messages.
    std::string equipmentNameForMessage = selectedEquipmentPtr->getName();
    bool continueLoop = true;

    while (continueLoop) {
        system("cls");
        // If the item was removed in the previous iteration (e.g., trashed),
        // we should exit this details view immediately.
        if (itemWasRemovedLocal) {
            return false; // Signal to calling function to refresh its list.
        }

        std::cout << "--- " << equipmentNameForMessage << " Stats ---\n\n";
        selectedEquipmentPtr->displayStats();
        std::cout << "\n";

        std::cout << "Choose an action:\n";
        for (int i = 0; i < numActions; ++i) {
            std::cout << ((actionSelection == i) ? "> " : "  ") << actions[i] << "\n";
        }

        std::cout << "\nUse Arrow keys to navigate, Z to select, X to go back, I to close inventory.\n";

        int actionInput = _getch(); // Get user input.

        switch (actionInput) {
        case 72: {// Move selection up.
            actionSelection = (actionSelection > 0) ? actionSelection - 1 : numActions - 1;
            break;
        }
        case 80: {// Move selection down.
            actionSelection = (actionSelection < numActions - 1) ? actionSelection + 1 : 0;
            break;
        }
	    actionInput = asciiToLower(actionInput); // Convert to lowercase.
        case 120:
            continueLoop = false;
            break;
        case 105:
            return true;
        case 122: { // Select an action.
            switch (actionSelection) {
            case 0: // Use (Equip) action.
                actionMessage = equipEquipmentAction(selectedEquipmentPtr);
                std::cout << actionMessage;
                break;
            case 1: // Unequip action.
                actionMessage = unequipEquipmentAction(selectedEquipmentPtr);
                std::cout << actionMessage;
                break;
            case 2: { // Trash/Delete action.
                int confirmSelection = 0;
                const int numConfirmOptions = 2;
                const std::string confirmOptions[] = { "Yes", "No" };
                bool confirmLoopRunning = true;

                while (confirmLoopRunning) {
                    system("cls"); // Clear screen for item details display
                    std::cout << "--- " << equipmentNameForMessage << " Stats ---\n\n";
                    selectedEquipmentPtr->displayStats();

                    std::cout << "\nAre you sure you want to trash " << equipmentNameForMessage << "?\n";
                    for (int i = 0; i < numConfirmOptions; ++i) {
                        std::cout << ((confirmSelection == i) ? "> " : "  ") << confirmOptions[i] << "\n";
                    }
                    std::cout << "\nUse Arrow keys to navigate, Z to select, X to cancel, I to close inventory.\n";

                    int confirmInput = _getch();

                    switch (confirmInput) {
                    case 72: {
                        confirmSelection = (confirmSelection > 0) ? confirmSelection - 1 : numConfirmOptions - 1;
                        break;
                    }
                    case 80: {
                        confirmSelection = (confirmSelection < numConfirmOptions - 1) ? confirmSelection + 1 : 0;
                        break;
                    }
					confirmInput = asciiToLower(confirmInput);
                    case 122:
                        if (confirmSelection == 0) { // Confirmed "Yes" to trash.
                            if (trashEquipmentAction(selectedEquipmentPtr, actualIndex)) {
                                actionMessage = equipmentNameForMessage + " has been TRASHED.\n";
                                itemWasRemovedLocal = true; // Mark item as removed.
                            }
                            else {
                                actionMessage = "Error: Failed to trash " + equipmentNameForMessage + ".\n";
                            }
                        }
                        else { // Confirmed "No" to trash.
                            actionMessage = "Trash cancelled.\n";
                        }
                        confirmLoopRunning = false;
                        system("cls");
                        break;
                    case 120:
                        actionMessage = "Trash cancelled.\n";
                        confirmLoopRunning = false;
                        break;
                    case 105:
                        return true;
                    default:
                        break;
                    }
                } // end while(confirmLoopRunning)
                break;
            }
            } // end switch(actionSelection)
            // If item was removed, break from this outer switch to re-evaluate the while loop.
            if (itemWasRemovedLocal) {
                break;
            }
            break;
        }
        default:
            break;
        }
    } // end while(true)
    return false; // Normal exit from item details to category list.
}

// Handles the detailed view and actions for a selected general item.
// Returns true if the inventory should be closed entirely, false to return to previous menu.
bool Inventory::handleItemDetailsAndActions(const std::string& selectedCategory, Items* selectedItemPtr, size_t actualIndex) {
	int actionSelection = 0;
	const int numActions = 2;
	const std::string actions[] = { "Use", "Trash/Delete" };
	std::string actionMessage = "";
	bool itemWasRemovedLocal = false;
	std::string itemNameForMessage = selectedItemPtr->getName();
	bool continueLoop = true;

	// This single flag controls the entire logic for the function.
	bool hasActions = !equalsIgnoreCaseASCII(selectedCategory, "Material");

	while (continueLoop) {
		system("cls");

		if (itemWasRemovedLocal) {
			return false;
		}

		// Always display the item stats.
		std::cout << "--- " << itemNameForMessage << " Stats ---\n\n";
		selectedItemPtr->displayStats();

		// Only display the action menu if the category has actions.
		if (hasActions) {
			std::cout << "\nChoose an action:\n";
			for (int i = 0; i < numActions; ++i) {
				std::cout << ((actionSelection == i) ? "> " : "  ") << actions[i] << "\n";
			}
		}

		std::cout << "\nUse Arrow keys to navigate, Z to select, X to go back, I to close inventory.\n";

		// Correctly handle two-character input for arrow keys.
		int input = _getch();
		if (input == 0 || input == 224) {
			input = _getch();
		}
		else {
			input = asciiToLower(input);
		}

		switch (input) {
		case 72: // Up Arrow
		case 80: // Down Arrow
			// Only allow navigation if the category has actions.
			if (hasActions) {
				if (input == 72) {
					actionSelection = (actionSelection > 0) ? actionSelection - 1 : numActions - 1;
				}
				else {
					actionSelection = (actionSelection < numActions - 1) ? actionSelection + 1 : 0;
				}
			}
			break;

		case 122: { // Z
			// Only allow the Z action if the category has actions.
			if (hasActions) {
				switch (actionSelection) {
				case 0: { // Use action
					// Call the updated useItemAction and check its return value.
					if (useItemAction(selectedItemPtr, actualIndex)) {
						// If the item was successfully used, we return true to close the inventory.
						return true;
					}
					break;
				}
				case 1: { // Trash/Delete action
					// Your existing trash confirmation logic.
					int confirmSelection = 0;
					const int numConfirmOptions = 2;
					const std::string confirmOptions[] = { "Yes", "No" };
					bool confirmLoopRunning = true;

					while (confirmLoopRunning) {
						system("cls");
						std::cout << "--- " << itemNameForMessage << " Stats ---\n\n";
						selectedItemPtr->displayStats();
						std::cout << "\nAre you sure you want to trash " << itemNameForMessage << "?\n";
						for (int i = 0; i < numConfirmOptions; ++i) {
							std::cout << ((confirmSelection == i) ? "> " : "  ") << confirmOptions[i] << "\n";
						}

						std::cout << "\nUse Arrow keys to navigate, Z to select, X to cancel, I to close inventory.\n";

						int confirmInput = _getch();

						if (confirmInput == 0 || confirmInput == 224) {
							confirmInput = _getch();
						}
						else {
							confirmInput = asciiToLower(confirmInput);
						}
						switch (confirmInput) {
						case 72:
							confirmSelection = (confirmSelection > 0) ? confirmSelection - 1 : numConfirmOptions - 1;
							break;
						case 80:
							confirmSelection = (confirmSelection < numConfirmOptions - 1) ? confirmSelection + 1 : 0;
							break;
						case 122:
							if (confirmSelection == 0) {
								if (trashItemAction(selectedItemPtr, actualIndex)) {
									actionMessage = itemNameForMessage + " has been TRASHED.\n";
									itemWasRemovedLocal = true;
								}
								else {
									actionMessage = "Error: Failed to trash " + itemNameForMessage + ".\n";
								}
							}
							else {
								actionMessage = "Trash cancelled.\n";
							}
							confirmLoopRunning = false;
							break;
						case 120: actionMessage = "Trash cancelled.\n"; confirmLoopRunning = false; break;
						case 105:
							return true;
						}
					}
				}
				}
			}
			break;
		}
		case 120: // X
			continueLoop = false;
			break;
		case 105: // I
			return true;
		default:
			break;
		}
	}
	return false;
}

// Handles the display and interaction for a specific equipment category.
// Returns true if the inventory should be closed entirely, false to return to previous menu.
bool Inventory::handleEquipmentCategoryItems(const std::string& selectedCategory) {
    int itemSelection = 0;
    int itemInput;

    const size_t MAX_CATEGORY_ITEMS = 100; // Max temporary array size for items in a category.
    Equipments* itemsInCategoryArray[MAX_CATEGORY_ITEMS];
    int itemsInCategoryCount = 0;
    bool Running = true;

    while (Running) {
        system("cls"); // Clear screen for category item list.
        std::cout << "--- " << selectedCategory << " Equipments ---\n\n";

        // Always re-fetch the list of items for the selected category.
        itemsInCategoryCount = getEquipmentsByType(selectedCategory, itemsInCategoryArray, MAX_CATEGORY_ITEMS);

        if (itemsInCategoryCount == 0) {
            std::cout << "\nPress any key to go back.\n"; // Prompt user to press a key.
            placeholderInt = _getch(); // Wait for user input.
            return false;
        }

        // Adjust itemSelection if it's out of bounds (e.g., due to item removal).
        if (itemSelection >= itemsInCategoryCount) {
            itemSelection = (itemsInCategoryCount > 0) ? itemsInCategoryCount - 1 : 0;
        }

        // Display items in the current category.
        for (int i = 0; i < itemsInCategoryCount; ++i) {
            std::cout << ((itemSelection == i) ? "> " : "  ") << itemsInCategoryArray[i]->getName() << "\n";
        }
        std::cout << "\nUse Arrow keys to navigate, Z to select, X to go back, I to close inventory.\n";

        itemInput = _getch(); // Get user input.

        switch (itemInput) {
        case 72: {// Move selection up.
            itemSelection = (itemSelection > 0) ? itemSelection - 1 : itemsInCategoryCount - 1;
            break;
        }
        case 80: {// Move selection down.
            itemSelection = (itemSelection < itemsInCategoryCount - 1) ? itemSelection + 1 : 0;
            break;
        }
		itemInput = asciiToLower(itemInput); // Convert to lowercase.
        case 122: { // Select an item.
            Equipments* selectedItem = itemsInCategoryArray[itemSelection];
            size_t actualIndex = findEquipmentIndex(selectedItem);

            if (actualIndex != (size_t)-1) {
                // Call handler for item details and actions.
                if (handleEquipmentDetailsAndActions(selectedCategory, selectedItem, actualIndex)) {
                    return true; // Propagate full inventory exit if requested from details.
                }
                // After returning from details, the list might have changed,
                // so the loop will re-fetch items and adjust selection as needed.
            }
            else {
                // Error handling if item not found (shouldn't happen if logic is correct).
                system("cls");
                std::cout << "\nPress any key to continue.\n"; // Prompt for continuation.
                placeholderInt = _getch(); // Wait for user input.
                break; // Break and let the loop re-evaluate the list.
            }
            break;
        }
        case 120: {
            Running = false;
            break;
        }
        case 105: {
            return true;
        }
        default: 
            break;
        }
    }
    return false; // Normal exit from category list to equipment section.
}

// Handles the display and interaction for a specific general item category.
// Returns true if the inventory should be closed entirely, false to return to previous menu.
bool Inventory::handleItemCategoryItems(const std::string& selectedCategory) {
    int itemSelection = 0;
    int itemInput;

    const size_t MAX_CATEGORY_ITEMS = 100; // Max temporary array size for items in a category.
    Items* itemsInCategoryArray[MAX_CATEGORY_ITEMS];
    int itemsInCategoryCount = 0;
    bool Running = true;

    while (Running) {
        system("cls"); // Clear screen for category item list.
        std::cout << "--- " << selectedCategory << " Items ---\n\n";

        // Always re-fetch the list of items for the selected category.
        itemsInCategoryCount = getItemsByType(selectedCategory, itemsInCategoryArray, MAX_CATEGORY_ITEMS);

        if (itemsInCategoryCount == 0) {
            std::cout << "\nPress any key to go back.\n"; // Prompt user to press a key.
            placeholderInt = _getch(); // Wait for user input.
            return false;
        }

        // Adjust itemSelection if it's out of bounds (e.g., due to item removal).
        if (itemSelection >= itemsInCategoryCount) {
            itemSelection = (itemsInCategoryCount > 0) ? itemsInCategoryCount - 1 : 0;
        }

        // Display items in the current category.
        for (int i = 0; i < itemsInCategoryCount; ++i) {
            std::cout << ((itemSelection == i) ? "> " : "  ") << itemsInCategoryArray[i]->getName() << "\n";
        }
        std::cout << "\nUse Arrow keys to navigate, Z to select, X to go back, I to close inventory.\n";

        itemInput = _getch(); // Get user input.

        switch (itemInput) {
        case 72: {// Move selection up.
            itemSelection = (itemSelection > 0) ? itemSelection - 1 : itemsInCategoryCount - 1;
            break;
        }
        case 80: {// Move selection down.
            itemSelection = (itemSelection < itemsInCategoryCount - 1) ? itemSelection + 1 : 0;
            break;
        }
        itemInput = asciiToLower(itemInput); // Convert to lowercase.
        case 122: { // Select an item.
            Items* selectedItem = itemsInCategoryArray[itemSelection];
            size_t actualIndex = findItemIndex(selectedItem);

            if (actualIndex != (size_t)-1) {
                // Call handler for item details and actions.
                if (handleItemDetailsAndActions(selectedCategory, selectedItem, actualIndex)) {
                    return true; // Propagate full inventory exit if requested from details.
                }
                // After returning from details, the list might have changed,
                // so the loop will re-fetch items and adjust selection as needed.
            }
            else {
                // Error handling if item not found (shouldn't happen if logic is correct).
                system("cls");
                std::cout << "\nPress any key to continue.\n"; // Prompt for continuation.
                placeholderInt = _getch(); // Wait for user input.
                break; // Break and let the loop re-evaluate the list.
            }
            break;
        }
        case 120: {
            Running = false;
            break;
        }
        case 105: {
            return true;
        }
        default: 
            break;
        }
    }
    return false; // Normal exit from category list to general items section.
}


// Handles the equipment section of the inventory, allowing selection of equipment categories.
// Returns true if the inventory should be closed entirely, false to return to main menu.
bool Inventory::handleEquipmentSection() {
    int categorySelection = 0;
    int keyInput;
    const int numCategories = 2; // WEAPON, ARMOR (add more as needed).
    const std::string categories[] = { "WEAPON", "ARMOR" };
    bool Running = true;

    while (Running) {
        system("cls"); // Clear screen for equipment section menu.
        std::cout << "--- Equipment Inventory ---\n\n";
        std::cout << "Equipment Space: " << currentEquipmentSize << "/" << maxEquipmentCapacity << "\n\n";

        std::cout << "Available Categories:\n";
        for (int i = 0; i < numCategories; ++i) {
            std::cout << ((categorySelection == i) ? "> " : "  ") << categories[i] << "\n";
        }
        std::cout << "\nUse Arrow keys to navigate, Z to select, X to go back, I to close inventory.\n";

        keyInput = _getch(); // Get user input.

        switch (keyInput) {
        case 72: {// Move selection up.
            categorySelection = (categorySelection > 0) ? categorySelection - 1 : numCategories - 1;
            break;
        }
        case 80: {// Move selection down.
            categorySelection = (categorySelection < numCategories - 1) ? categorySelection + 1 : 0;
            break;
        }
		keyInput = asciiToLower(keyInput); // Convert to lowercase.
        case 122: { // Select a category.
            // Call handler for selected category items.
            if (handleEquipmentCategoryItems(categories[categorySelection])) {
                return true; // Propagate full inventory exit if requested from deeper menu.
            }
            break;
        }
        case 120: {
            Running = false;
            break;
        }
        case 105: {
            return true;
        }
        default: 
            break;
        }
    }
    return false; // Normal exit, go back to main inventory selection.
}

// Handles the general items section of the inventory, allowing selection of item categories.
// Returns true if the inventory should be closed entirely, false to return to main menu.
bool Inventory::handleItemSection() {
    int categorySelection = 0;
    int keyInput;
    const int numCategories = 3; 
    const std::string categories[] = { "POTION", "MATERIAL", "MISCELLANEOUS"}; // categories.
    bool Running = true;

    while (Running) {
        system("cls"); // Clear screen for general items section menu.
        std::cout << "--- General Items Inventory ---\n\n";

        std::cout << "Available Categories:\n";
        for (int i = 0; i < numCategories; ++i) {
            std::cout << ((categorySelection == i) ? "> " : "  ") << categories[i] << "\n";
        }
        std::cout << "\nUse Arrow keys to navigate, Z to select, X to go back, I to close inventory.\n";

        keyInput = _getch(); // Get user input.

        switch (keyInput) {
        case 72: {// Move selection up.
            categorySelection = (categorySelection > 0) ? categorySelection - 1 : numCategories - 1;
            break;
        }
        case 80: { // Move selection down.
            categorySelection = (categorySelection < numCategories - 1) ? categorySelection + 1 : 0;
            break;
        }
	    keyInput = asciiToLower(keyInput); // Convert to lowercase.
        case 122: { // Select a category.
            // Call handler for selected category items.
            if (handleItemCategoryItems(categories[categorySelection])) {
                return true; // Propagate full inventory exit if requested from deeper menu.
            }
            break;
        }
        case 120: {
            Running = false;
            break;
        }
        case 105: {
            return true;
        }
        default: 
            break;
        }
    }
    return false; // Normal exit, go back to main inventory selection.
}


// Opens the main inventory menu, allowing selection between equipment and general items sections.
void Inventory::openInventory()
{
    //if (!inventoryOpened)
    //{
    //    addItem(stonePtr);
    //    addItem(woodPtr);
    //    inventoryOpened = true;
    //}
    
    int currentSelection = 0;
    int keyInput;
    const int numMainOptions = 2; // View Equipments, View Items.
    const std::string mainOptions[] = { "View Equipments", "View Items" };

    while (true) {
        system("cls"); // Clear screen for main inventory menu.
        std::cout << "--- Main Inventory Menu ---\n\n";

        // Display current item and equipment space.
        std::cout << "Equipment Space: " << currentEquipmentSize << "/" << maxEquipmentCapacity << "\n";

        std::cout << "Select a Section:\n";
        for (int i = 0; i < numMainOptions; ++i) {
            std::cout << ((currentSelection == i) ? "> " : "  ") << mainOptions[i] << "\n";
        }
        std::cout << "\nUse Arrow keys to navigate, Z to select, I to close inventory.\n";

        keyInput = _getch(); // Get user input.

        switch (keyInput) {
        case 72: {// Move selection up.
            currentSelection = (currentSelection > 0) ? currentSelection - 1 : numMainOptions - 1;
            break;
        }
        case 80: {// Move selection down.
            currentSelection = (currentSelection < numMainOptions - 1) ? currentSelection + 1 : 0;
            break;
        }
		keyInput = asciiToLower(keyInput); // Convert to lowercase.
        case 122: { // Select a main option.
            switch (currentSelection) {
            case 0: // View Equipments section.
                if (handleEquipmentSection()) {
                    return; // Propagate full inventory exit if requested from deeper menu.
                }
                break;
            case 1: // View General Items section.
                if (handleItemSection()) {
                    return; // Propagate full inventory exit if requested from deeper menu.
                }
                break;
            }
            break;
        }
        case 120:
        case 105:
            std::cout << "\nExiting Inventory. Goodbye!\n";
            return;
        default:
            break;
        }
    }

}
