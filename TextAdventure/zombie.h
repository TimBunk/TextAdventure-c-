#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Player;

class Zombie {

	public:
		Zombie(int health, int damage, bool appliesBleed, int respawnTime);
		~Zombie();

		int DoDamage();
		bool AppliesBleed();
		void TakeDamage(int amount);
		bool IsAlive();
		std::string GetInfo();
		void GiveName(std::string name);
		std::string GetName();
		void IncreaseDeathTime();
		bool RespawnAvailable();
		void Respawned();

	protected:

	private:
		std::string name;
		int health;
		int originalHealth;
		int damage;
		bool appliesBleed;
		int respawnTime;
		int deadCount = 0;
};

#endif // !ZOMBIE_H
