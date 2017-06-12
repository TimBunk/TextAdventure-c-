#include "zombie.h"
#include "player.h"

Zombie::Zombie(int health, int damage, bool appliesBleed)
{
	this->health = health;
	this->damage = damage;
	this->appliesBleed = appliesBleed;
}

Zombie::~Zombie()
{

}

void Zombie::DoDamage(Player* player)
{
	std::cout << "the player got attacked by "<< name << std::endl;
	player->ApplyDamage(damage, appliesBleed);
}

void Zombie::TakeDamage(int amount)
{
	//std::cout << name << " took " << amount << " damage" << std::endl;
	health -= amount;
}

bool Zombie::IsAlive()
{
	if (health > 0) {
		return true;
	}
	return false;
}

std::string Zombie::GetInfo()
{
	std::string info = "(health " + std::to_string(health) + ", damage " + std::to_string(damage) + ")";
	return info;
}

void Zombie::GiveName(std::string name)
{
	this->name = name;
}

std::string Zombie::GetName()
{
	return name;
}
