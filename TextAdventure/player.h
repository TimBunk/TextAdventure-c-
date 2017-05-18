#pragma once

#include <iostream>
#include <string>
#include "room.h"
#include "command.h"

class player
{
public:
	player();
	~player();
	void setCurrentRoom(Room *room);
	void describeRoom();
	void goRoom(Command cmd);

private:
	Room* currentRoom;
};

