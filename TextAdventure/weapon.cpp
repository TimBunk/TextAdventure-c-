#include "weapon.h"

Weapon::Weapon(std::string name, int weight, std::string description, std::string attackDescription, int damage, int hitAmount, int durability) : Item::Item(name,weight,description)
{
	this->attackDescription = attackDescription;
	this->damage = damage;
	this->hitAmount = hitAmount;
	this->durability = durability;
}

Weapon::~Weapon()
{

}

void Weapon::Use(Room* room)
{
	std::cout << attackDescription << std::endl;
	room->AttackZombie(damage, hitAmount);
	DecreaseDurability();
}

bool Weapon::IsAlive()
{
	if (durability > 0) {
		return true;
	}
	return false;
}

void Weapon::DecreaseDurability()
{
	durability--;
}
