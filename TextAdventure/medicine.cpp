#include "medicine.h"
#include "player.h"

Medicine::Medicine(std::string name, int weight, std::string description, int healing, bool bleeding) : Item::Item(name,weight,description)
{
	this->healing = healing;
	this->bleeding = bleeding;
}

Medicine::~Medicine()
{
}

std::string Medicine::GetInfo()
{
	std::string info = name + ", weight: " + std::to_string(weight) + ", healing: " + std::to_string(healing) + ", description: " + description;
	return info;
}

void Medicine::Use(Player* player)
{
	player->ApplyHeal(healing, bleeding);
}