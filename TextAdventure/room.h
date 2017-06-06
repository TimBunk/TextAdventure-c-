#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "key.h"
#include "item.h"
#include "zombie.h"

class Room
{
public:
	Room(std::string name, std::string desc);
	virtual ~Room();

	void setExit(std::string direction, Room* neighbor);
	Room* getExit(std::string direction);

	std::string GetName();
	std::string getLongDescription() { return "You are " + description + '\n' + getExitString(); }
	std::string getShortDescription() { return "You are " + description; }
	std::string getExitString();
	
	void LockRoom(Key *key);
	std::string GetKeyName();
	void UnlockRoom(std::string keyName);
	bool CheckLock();
	
	void PlaceItem(Item* item);
	void RemoveItem(std::string nameItem);
	Item* GetItem(std::string nameItem);
	bool ContainsItems();
	void PrintItems();

	void PlaceZombie(Zombie* zombie);
	bool ConatainsZombies();
	void PrintZombies();

private:
	std::string name;
	std::string description;
	std::map<std::string, Room*> exits;

	Key* key;
	bool lock = false;
	
	std::vector<Item*> items;
	std::vector<Zombie*> zombies;
};

#endif
