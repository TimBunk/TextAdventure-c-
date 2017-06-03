#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>

#include "item.h"

class Key : public Item
{	
	public:

		Key(std::string name, int weight, std::string description);
		~Key();

	private:

};
#endif