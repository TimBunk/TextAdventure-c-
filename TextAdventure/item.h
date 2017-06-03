#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item
{
public:
	Item(std::string name, int weight);
	~Item();
	std::string GetName();
	int GetWeight();
	virtual std::string GetInfo();
	void virtual Use();

private:
	std::string name;
	int weight;

protected:
	
};

#endif