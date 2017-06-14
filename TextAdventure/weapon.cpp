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

std::string Weapon::GetInfo()
{
	std::string info = GetName() + ", weight: " + std::to_string(GetWeight()) + ", damage: " + std::to_string(damage)  + ", hitAmount: " + std::to_string(hitAmount) + ", durability: " + std::to_string(durability) + ", description: " + description;
	return info;
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
