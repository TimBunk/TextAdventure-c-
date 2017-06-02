#include "backpack.h"

Backpack::Backpack(int capacity)
{
	this->capacity = capacity;
}

Backpack::~Backpack()
{

}

void Backpack::Add(Item item)
{
	if (GetCurrentWeight() + item.GetWeight() <= capacity) {
		inventory.push_back(item);
		std::cout << "Added " << item.GetName() << " to backpack" << std::endl;
		std::cout << "New inventory capacity = " << GetCurrentWeight() << "/" << capacity << std::endl;
	}
	else {
		PrintOverCapacity(item);
	}
}

void Backpack::Remove(std::string name)
{
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i].GetName().compare(name) == 0) {
			std::cout << "New inventory capacity = "<< GetCurrentWeight() << "/" << capacity << std::endl;
			inventory.erase(inventory.begin() + i);
			return;
		}
	}
}

int Backpack::GetCurrentWeight()
{
	int totalWeight = 0;
	for (int i = 0; i < inventory.size(); i++) {
		totalWeight += inventory[i].GetWeight();
	}
	return totalWeight;
}

int Backpack::GetCapacity()
{
	return capacity;
}

void Backpack::PrintOverCapacity(Item item)
{
	std::cout << item.GetName() << " weights " << item.GetWeight() << " and your inventories capacity = " << GetCurrentWeight() << "/" << capacity << std::endl;
}

Item Backpack::GetItem(std::string name)
{
	Item *item;
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i].GetName().compare(name) == 0) {
			item = &inventory[i];
			return *item;
		}
	}
	// if item is not found return a item with name nothing
	item = new Item("nothing", 0);
	return *item;
}

void Backpack::PrintInventory()
{
	std::cout << "Inventory Capacity = " << GetCurrentWeight() << "/" << capacity << std::endl;
	for (int i = 0; i < inventory.size(); i++) {
		std::cout << inventory[i].GetInfo() << std::endl;
	}
}
