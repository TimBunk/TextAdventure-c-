#pragma once

#include <iostream>
#include <string>
#include "room.h"
#include "command.h"

class Player
{
public:
	Player();
	~Player();

	void setCurrentRoom(Room *room);
	void describeRoom();
	void goRoom(Command cmd);

	void PrintHealth();
	void ApplyDamage(int amount);
	void ApplyHeal(int amount);
	bool IsAlive();

private:
	Room* currentRoom;
	int health = 15;
};

