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
		Key(std::string name, int weight);// : Item(name, weight);
		//Key(std::string name, int weight);
		
		~Key();
		void printff();
	private:

};
#endif