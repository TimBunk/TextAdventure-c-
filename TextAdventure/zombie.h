#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {

	public:
		Zombie(std::string name, int health, int damage, bool appliesBleed);
		~Zombie();

		std::string GetName();

	protected:

	private:
		std::string name;
		int health;
		int damage;
		bool appliesBleed;
};

#endif // !ZOMBIE_H
