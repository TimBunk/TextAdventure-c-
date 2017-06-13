#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "room.h"
#include "command.h"
#include "inventory.h"
#include "item.h"
#include "key.h"
#include "medicine.h"
#include "weapon.h"

class Player
{
public:
	Player(int health, int backpackCapacity);
	~Player();

	void setCurrentRoom(Room *room);
	void describeRoom();
	void goRoom(Command cmd);

	void PrintHealth();
	void ApplyDamage(int amount, bool startsBleeding);
	void ApplyHeal(int amount, bool stopsBleeding);
	bool IsAlive();
	
	void PrintBackpackInfo();
	void AddItem(Item* item);
	void DropItem(Command cmd);
	void PickUp(Command cmd);
	void UseItem(Command cmd);

private:
	Room* currentRoom;
	Inventory* backpack;

	bool bleeding = false;
	int maxHealth;
	int health;
	
};

#endif