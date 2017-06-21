#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item
{
public:
	Item(std::string name, int weight, std::string description);
	~Item();
	std::string GetName();
	int GetWeight();
	virtual std::string GetInfo();
	virtual void Use();

private:
	

protected:
	std::string name;
	int weight;
	std::string description;
};

#endif