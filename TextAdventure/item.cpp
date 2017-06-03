#include <iostream>
#include "item.h"

Item::Item(std::string name, int weight, std::string description)
{
	this->name = name;
	this->weight = weight;
	this->description = description;
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

std::string Item::GetInfo()
{
	std::string info = GetName() + ", weight: " + std::to_string(GetWeight()) + ", description: " + description;
	return info;
}

void Item::Use()
{
	std::cout << "You can not use that right now" << std::endl;
}
