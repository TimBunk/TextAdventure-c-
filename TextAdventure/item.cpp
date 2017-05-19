#include <iostream>
#include "item.h"

Item::Item(std::string name, int weight)
{
	this->name = name;
	this->weight = weight;
}

Item::~Item()
{
}

std::string Item::GetName()
{
	return name;
}

int Item::GetWeight()
{
	return weight;
}
