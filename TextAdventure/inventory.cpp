#include "inventory.h"

Inventory::Inventory(int capacity)
{
	this->capacity = capacity;
}

Inventory::~Inventory()
{
}

void Inventory::Add(Item* item)
{
	if (GetCurrentWeight() + item->GetWeight() <= capacity) {
		inventory.push_back(item);
	}
}

void Inventory::Remove(std::string name)
{
	std::vector<Item*>::iterator it = inventory.begin();

	while (it != inventory.end()) {
		if ((*it)->GetName().compare(name) == 0) {
			it = inventory.erase(it);
		}
		else {
			++it;
		}
	}
}

Item * Inventory::GetItem(std::string name)
{
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->GetName().compare(name) == 0) {
			return inventory[i];
		}
	}
	// if item is not found return NULL
	return NULL;
}

int Inventory::GetCurrentWeight()
{
	int totalWeight = 0;
	for (int i = 0; i < inventory.size(); i++) {
		totalWeight += inventory[i]->GetWeight();
	}
	return totalWeight;
}

int Inventory::GetCapacity()
{
	return capacity;
}

void Inventory::PrintInventory()
{
	for (int i = 0; i < inventory.size(); i++) {
		std::cout << inventory[i]->GetInfo() << std::endl;
	}
}

bool Inventory::ContainsItems()
{
	if (inventory.size() > 0) {
		return true;
	}
	return false;
}
