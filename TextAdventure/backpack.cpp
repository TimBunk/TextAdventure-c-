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
		std::cout << item.GetName() << " weights " << item.GetWeight() << " and your inventories capacity = " << GetCurrentWeight() << "/" << capacity << std::endl;
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

void Backpack::PrintInventory()
{
	std::cout << "Inventory Capacity = " << GetCurrentWeight() << "/" << capacity << std::endl;
	for (int i = 0; i < inventory.size(); i++) {
		std::cout << inventory[i].GetInfo() << std::endl;
	}
}
