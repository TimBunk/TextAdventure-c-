#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

#include "item.h"
#include "room.h"

class Weapon : public Item {

	public:
		Weapon(std::string name, int weight, std::string description, std::string attackDescription, int damage, int hitAmount, int durability);
		~Weapon();

		virtual void Use(Room* room);

		bool IsAlive();

	protected:
		std::string attackDescription;
		int damage;
		int hitAmount; // How many zombies you can hit in 1 turn
		int durability;
		void DecreaseDurability();

	private:

};
#endif // !WEAPON_H