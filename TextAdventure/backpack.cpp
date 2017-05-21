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
	inventory.push_back(item);
	std::cout << item.GetName() << std::endl;
}
