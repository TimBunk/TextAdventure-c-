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
	Player();
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
	void AddItem(Item item);

private:
	Room* currentRoom;
	int health = 15;
	Backpack* backpack;
};

#endif