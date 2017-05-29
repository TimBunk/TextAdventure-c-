#include "medicine.h"

Medicine::Medicine(std::string name, int weight, int healing) : Item::Item(name,weight)
{
	this->healing = healing;
}

Medicine::~Medicine()
{

}

int Medicine::ApplyHealing()
{
	return healing;
}
