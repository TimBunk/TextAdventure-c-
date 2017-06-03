#include "room.h"

Room::Room(std::string name, std::string desc)
{
	this->name = name;
	this->description = desc;
}

Room::~Room()
{
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

std::string Room::GetName()
{
	return name;
}

std::string Room::getExitString()
{
	std::string returnString = "Exits: ";
	std::map<std::string,Room*>::iterator it = exits.begin();
	while (it != exits.end()) {
		returnString += it->first;
		returnString += "(" + exits[it->first]->GetName() + ")";
		returnString += " ";
		++it;
	}
	return returnString;
}

void Room::LockRoom(Key* key)
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
	items.push_back(item);
}

void Room::RemoveItem(std::string nameItem)
{
	std::vector<Item*>::iterator it = items.begin(); // get the 'iterator' from the list.
													// 'it' is a pointer to the first element in the list (which is a Item pointer).
	while (it != items.end()) {
		if ((*it)->GetName().compare(nameItem) == 0) { // de-reference the iterator pointer (results in the Item pointer itself).
			it = items.erase(it); // 'remove' from items list. 'erase' returns a pointer to the next element in the list.
		}
		else {
			++it; // pointer arithmetic. "make 'it' point to the next element".
		}
	}
}

Item* Room::GetItem(std::string nameItem)
{
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->GetName().compare(nameItem) == 0) {
			return items[i];
		}
	}
	return NULL;
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