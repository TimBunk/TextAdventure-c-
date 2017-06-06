#include "zombie.h"

Zombie::Zombie(std::string name, int health, int damage, bool appliesBleed)
{
	this->name = name;
	this->health = health;
	this->damage = damage;
	this->appliesBleed = appliesBleed;
}

Zombie::~Zombie()
{
}
