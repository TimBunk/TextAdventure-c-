// room.cpp

#include "room.h"

Room::Room(std::string desc)
{
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

void Room::PlaceItem(Item item)
{
	items.push_back(item);
}

void Room::RemoveItem(std::string nameItem)
{
	for (int i = 0; i < items.size(); i++) {
		if (items[i].GetName().compare(nameItem) == 0) {
			items.erase(items.begin() + i);
		}
	}
}

Item Room::GetItem(std::string nameItem)
{
	Item *item;
	for (int i = 0; i < items.size(); i++) {
		if (items[i].GetName().compare(nameItem) == 0) {
			item = &items[i];
			return *item;
		}
	}
	// if item is not found return a item with name nothing
	item = new Item("nothing", 0);
	return *item;
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
		std::cout << items[i].GetName();
		if (i + 1 != items.size()) {
			std::cout << ", ";
		}
		else {
			std::cout << "" << std::endl;
		}
	}
}
