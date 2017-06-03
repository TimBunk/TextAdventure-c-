#include "medicine.h"

Medicine::Medicine(std::string name, int weight, std::string description, int healing) : Item::Item(name,weight,description)
{
	this->healing = healing;
}

Medicine::~Medicine()
{

}

std::string Medicine::GetInfo()
{
	std::string info = name + ", weight: " + std::to_string(weight) + ", description: " + description;
	return info;
}

int Medicine::ApplyHealing()
{
	return healing;
}
