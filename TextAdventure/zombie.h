#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Player;

class Zombie {

	public:
		Zombie(int health, int damage, bool appliesBleed);
		~Zombie();

		int DoDamage();
		bool AppliesBleed();
		void TakeDamage(int amount);
		bool IsAlive();
		std::string GetInfo();
		void GiveName(std::string name);
		std::string GetName();

	protected:

	private:
		std::string name;
		int health;
		int damage;
		bool appliesBleed;
};

#endif // !ZOMBIE_H
