#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
#include <string>

#include "item.h"

class Player;

class Medicine : public Item {

	public:
		Medicine(std::string name, int weight, std::string description, int healing, bool stopsBleeding);
		~Medicine();

		std::string GetInfo();
		void Use(Player* player);

		bool StopsBleeding();
		bool Healing();

	private:

		int healing;
		bool stopsBleeding;
};

#endif