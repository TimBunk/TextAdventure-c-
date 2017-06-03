#ifndef BACKPACK_H
#define BACKPACK_H

#include <iostream>
#include <string>
#include <vector>

#include "item.h"
#include "key.h"

class Backpack
{
public:
	Backpack(int capacity);
	~Backpack();

	void Add(Item* item);
	void Remove(std::string name);
	int GetCurrentWeight();
	int GetCapacity();
	void PrintOverCapacity(Item* item);
	Item* GetItem(std::string name);
	void PrintInventory();

private:
	int capacity;
	std::vector<Item*> inventory;
};

#endif