#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>

#include "room.h"
#include "item.h"

class Key : public Item
{	
	using Item::Item;

	public:

		Key(Room keyRoom, std::string name, int weight);
		~Key();

		Room GetKeyRoom();

	private:
		Room* keyRoom;
};
#endif