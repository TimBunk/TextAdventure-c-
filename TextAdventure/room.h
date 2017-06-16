#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "inventory.h"
#include "key.h"
#include "item.h"
#include "zombie.h"

class Player;

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
	std::vector<std::string> getExitsVector();
	
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
	void ZombiesAttack(Player* player);
	void AttackZombie(int damage, int hitAmount);
	void UpdateZombies();

private:
	std::string name;
	std::string description;
	std::map<std::string, Room*> exits;
	std::vector<std::string> exitsStrings;

	Key* key;
	bool lock = false;
	
	Inventory* items;
	std::vector<Zombie*> zombies;
	void RespawnZombie(Zombie* zombie);
	std::vector<Zombie*> deadZombies;
	int zombieCount = 1;
	int zombieRespawnTime = 3;
};

#endif
