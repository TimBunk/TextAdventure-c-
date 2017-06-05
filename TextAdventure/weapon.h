#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

#include "item.h"

class Weapon : public Item {

	public:
		Weapon(std::string name, int weight, std::string description);
		~Weapon();

		virtual void Use();

	private:

};
#endif // !WEAPON_H