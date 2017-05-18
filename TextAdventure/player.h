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

private:
	Room* currentRoom;
};

