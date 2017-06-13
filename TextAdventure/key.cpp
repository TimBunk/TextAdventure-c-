#include "key.h"
#include "room.h"

Key::Key(std::string name, int weight, std::string description) : Item::Item(name,weight,description)
{
}

Key::~Key()
{

}

void Key::Use(Room* room)
{
	Room* nextRoom;
	std::vector<std::string> exits = room->getExitsVector();
	for (int i = 0; i < exits.size(); i++) {
		nextRoom = room->getExit(exits[i]);
		if (nextRoom->CheckLock()) {
			nextRoom->UnlockRoom(name);
			if (!nextRoom->CheckLock()) {
				succeeded = exits[i];
			}
		}
	}
}

std::string Key::Succeeded()
{
	//If it succeeded it returns the name of the directions that you unlocked else it returns an empty string
	return succeeded;
}
