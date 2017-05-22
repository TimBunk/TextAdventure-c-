// room.h

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include <string>

#include "key.h"

class Room
{
public:
	Room(std::string desc);
	virtual ~Room();

	void setExit(std::string direction, Room* neighbor);
	Room* getExit(std::string direction);

	std::string getLongDescription() { return "You are " + description + '\n' + getExitString(); }
	std::string getExitString();
	
	//void LockRoom(Key key);
	bool CheckLock();

private:
	std::string description;
	std::map<std::string, Room*> exits;
	bool lock = false;
};

#endif /* ROOM_H */
