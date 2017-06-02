// room.cpp

#include "room.h"

Room::Room(std::string desc)
{
	this->description = desc;
}

Room::~Room()
{
	//delete items;
}

void Room::setExit(std::string direction, Room* neighbor)
{
	exits[direction] = neighbor;
}

Room* Room::getExit(std::string direction)
{
	if (exits.find(direction) != exits.end()) {
		return exits[direction];
	}
	return NULL;
}

std::string Room::getExitString()
{
	std::string returnString = "Exits: ";
	std::map<std::string,Room*>::iterator it = exits.begin();
	while (it != exits.end()) {
		returnString += it->first;
		returnString += " ";
		++it;
	}

	return returnString;
}

void Room::LockRoom(Key *key)
{
	lock = true;
	this->key = key;
}

std::string Room::GetKeyName()
{
	return this->key->GetName();
}

void Room::UnlockRoom(std::string keyName)
{
	if (this->key->GetName().compare(keyName) == 0) {
		std::cout << "You unloced the room... ";
		lock = false;
	}
}

bool Room::CheckLock()
{
	return lock;
}

void Room::PlaceItem(Item* item)
{
	std::cout << "Adress in room: " << item << std::endl;
	items.push_back(item);
}

void Room::RemoveItem(std::string nameItem)
{
	std::vector<Item*>::iterator it = items.begin(); // get the 'iterator' from the list.
													// 'it' is a pointer to the first element in the list (which is a Bullet pointer).
	int counter = 0;
	while (it != items.end()) {
		if ((*it)->GetName().compare(nameItem) == 0) { // de-reference the iterator pointer (results in the Bullet pointer itself).
			std::cout << "-- deleting Item " << counter << " : (" << (*it)->GetName() << ")" << std::endl;
			it = items.erase(it); // 'remove' from bullet list. 'erase' returns a pointer to the next element in the list.
		}
		else {
			++it; // pointer arithmetic. "make 'it' point to the next element".
		}
		++counter;
	}
}

Item* Room::GetItem(std::string nameItem)
{
	//Item *item;
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->GetName().compare(nameItem) == 0) {
			//item = items[i];
			return items[i];
		}
	}
	// if item is not found return a item with name nothing
	//item = new Item("nothing", 0);
	//return *item;
}

bool Room::ContainsItems()
{
	if (items.size() >= 1) {
		return true;
	}
	else {
		return false;
	}
}

void Room::PrintItems()
{
	for (int i = 0; i < items.size(); i++) {
		std::cout << items[i]->GetName();
		if (i + 1 != items.size()) {
			std::cout << ", ";
		}
		else {
			std::cout << std::endl;
		}
	}
}
