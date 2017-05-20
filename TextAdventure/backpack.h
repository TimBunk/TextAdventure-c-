#include <string>
#include <vector>
#include "item.h"

class Backpack
{
public:
	Backpack(int capacity);
	~Backpack();

	void Add(Item item);

private:
	int capacity;
	std::vector<Item> inventory;
};