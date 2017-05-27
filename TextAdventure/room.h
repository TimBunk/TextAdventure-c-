// room.h

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "key.h"
#include "item.h"

class Room
{
public:
	Room(std::string desc);
	virtual ~Room();

	void setExit(std::string direction, Room* neighbor);
	Room* getExit(std::string direction);

	std::string getLongDescription() { return "You are " + description + '\n' + getExitString(); }
	std::string getExitString();
	
	void LockRoom(Key *key);
	std::string GetKeyName();
	void UnlockRoom(std::string keyName);
	bool CheckLock();

	std::vector<Item> items;
	void PlaceItem(Item item);

private:
	std::string description;
	std::map<std::string, Room*> exits;
	Key *key;
	bool lock = false;
};

#endif /* ROOM_H */
