#include "player.h"


Player::Player()
{
}

Player::~Player()
{
}

void Player::setCurrentRoom(Room *room)
{
	currentRoom = room;
}

void Player::describeRoom()
{
	std::cout << currentRoom->getLongDescription() << std::endl;
}

void Player::goRoom(Command cmd)
{
	if (!cmd.hasSecondWord()) {
		// if there is no second word, we don't know where to go...
		std::cout << "Go where?" << std::endl;
		return;
	}

	std::string direction = cmd.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->getExit(direction);

	if (nextRoom == NULL) {
		std::cout << "There is no door!" << std::endl;
	}
	else {
		currentRoom = nextRoom;
		std::cout << currentRoom->getLongDescription() << std::endl;
	}
}
