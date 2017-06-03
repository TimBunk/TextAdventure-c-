#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "room.h"
#include "command.h"
#include "backpack.h"
#include "item.h"
#include "key.h"
#include "medicine.h"

class Player
{
public:
	Player(int health, int backpackCapacity);
	~Player();

	void setCurrentRoom(Room *room);
	void describeRoom();
	void goRoom(Command cmd);
	void UnlockRoom(Command cmd);

	void PrintHealth();
	void ApplyDamage(int amount, bool bleeding);
	void ApplyHeal(int amount, bool bleeding);
	bool IsAlive();
	
	void PrintBackpackInfo();
	void AddItem(Item* item);
	void DropItem(Command cmd);
	void PickUp(Command cmd);
	void UseItem(Command cmd);

private:
	Room* currentRoom;
	Backpack* backpack;

	bool bleeding = false;
	int maxHealth;
	int health;
	
};

#endif