#include "zombie.h"
#include "player.h"

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

std::string Zombie::GetName()
{
	return name;
}

void Zombie::DoDamage(Player* player)
{
	std::cout << name << " attacked the player" << std::endl;
	player->ApplyDamage(damage, appliesBleed);
}

void Zombie::TakeDamage(int amount)
{
	std::cout << name << " took " << amount << " damage" << std::endl;
	health -= amount;
}