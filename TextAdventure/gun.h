#ifndef GUN_H
#define GUN_H

#include <iostream>
#include <string>

#include "weapon.h"

class Gun : public Weapon {

	public:
		Gun(std::string name, int weight, std::string description, int damage, int durability);
		~Gun();

	private:

};

#endif // !GUN_H
