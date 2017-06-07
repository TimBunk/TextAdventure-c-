#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

#include "item.h"

class Weapon : public Item {

	public:
		Weapon(std::string name, int weight, std::string description, int damage, int durability);
		~Weapon();

		virtual void Use();

	protected:
		int damage;
		int durability;
		void DecreaseDurability();

	private:

};
#endif // !WEAPON_H