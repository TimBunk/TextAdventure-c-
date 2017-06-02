#include "medicine.h"

Medicine::Medicine(std::string name, int weight, int healing) : Item::Item(name,weight)
{
	this->healing = healing;
}

Medicine::~Medicine()
{

}

std::string Medicine::GetInfo()
{
	std::string info = GetName() + ", weight: " + std::to_string(GetWeight()) + ", healing: " + std::to_string(healing);
	return info;
}

int Medicine::ApplyHealing()
{
	return healing;
}
