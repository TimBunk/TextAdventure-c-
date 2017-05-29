#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
#include <string>

#include "item.h"

class Medicine : public Item {

	public:

		Medicine(std::string name, int weight, int healing);
		~Medicine();

		int ApplyHealing();

	private:

		int healing;

};

#endif