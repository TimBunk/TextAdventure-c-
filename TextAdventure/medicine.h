#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
#include <string>

#include "item.h"

class Player;

class Medicine : public Item {

	public:
		Medicine(std::string name, int weight, std::string description, int healing, bool bleeding);
		~Medicine();

		virtual std::string GetInfo();
		virtual void Use(Player* player);

	private:

		int healing;
		bool bleeding;
};

#endif