#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>

#include "item.h"

class Inventory {
public:
	Inventory(int capacity);
	~Inventory();

	void Add(Item* item);
	void Remove(std::string name);
	Item* GetItem(std::string name);
	int GetCurrentWeight();
	int GetCapacity();
	void PrintInventory();
	bool ContainsItems();

private:
	int capacity;
	std::vector<Item*> inventory;

};
#endif // !INVENTORY_H