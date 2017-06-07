#include "weapon.h"

Weapon::Weapon(std::string name, int weight, std::string description, int damage, int durability) : Item::Item(name,weight,description)
{
	this->damage = damage;
	this->durability = durability;
}

Weapon::~Weapon()
{

}

void Weapon::Use()
{
	
}

void Weapon::DecreaseDurability()
{
	durability--;
}
