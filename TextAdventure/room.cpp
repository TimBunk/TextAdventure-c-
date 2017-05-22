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

/*void Room::LockRoom(Key key)
{
	lock = true;
	this->key = &key;
}*/

bool Room::CheckLock()
{
	return lock;
}
