#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>

#include "item.h"

class Room;

class Key : public Item
{	
	public:

		Key(std::string name, int weight, std::string description);
		~Key();

		void Use(Room* room);
		std::string Succeeded();

	private:
		std::string succeeded = "";
};
#endif