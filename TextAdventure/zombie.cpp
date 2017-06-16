#include "zombie.h"
#include "player.h"

Zombie::Zombie(int health, int damage, bool appliesBleed, int respawnTime)
{
	this->health = health;
	this->originalHealth = health;
	this->damage = damage;
	this->appliesBleed = appliesBleed;
	this->respawnTime = respawnTime;
}

Zombie::~Zombie()
{

}

int Zombie::DoDamage()
{
	return damage;
}

bool Zombie::AppliesBleed()
{
	return appliesBleed;
}

void Zombie::TakeDamage(int amount)
{
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

void Zombie::IncreaseDeathTime()
{
	deadCount++;
}

bool Zombie::RespawnAvailable()
{
	if (deadCount >= respawnTime) {
		return true;
	}
	return false;
}

void Zombie::Respawned()
{
	deadCount = 0;
	health = originalHealth;
}
