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
	void ApplyDamage(int amount);
	void ApplyHeal(int amount);
	bool IsAlive();
	
	void PrintBackpackInfo();
	void AddItem(Item* item);
	void DropItem(Command cmd);
	void PickUp(Command cmd);
	void UseItem(Command cmd);

private:
	Room* currentRoom;
	int maxHealth;
	int health;
	Backpack* backpack;
};

#endif