#ifndef BACKPACK_H
#define BACKPACK_H

#include <iostream>
#include <string>
#include <vector>

#include "item.h"

class Backpack
{
public:
	Backpack(int capacity);
	~Backpack();

	void Add(Item item);
	int GetCurrentWeight();
	void PrintInventory();

private:
	int capacity;
	std::vector<Item> inventory;
};

#endif