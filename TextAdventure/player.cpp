#include "player.h"


Player::Player()
{
	backpack = new Backpack(20);
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
		ApplyDamage(1);
		std::cout << currentRoom->getLongDescription() << std::endl;
	}
}

void Player::PrintHealth()
{
	std::cout << health << std::endl;
}

void Player::ApplyDamage(int amount)
{
	health -= amount;
	std::cout << "You took " << amount << " damage, you're current health is now ";
	PrintHealth();
}

void Player::ApplyHeal(int amount)
{
	health += amount;
	std::cout << "You healed for " << amount; " , you're current health is now ";
	PrintHealth();
}

bool Player::IsAlive()
{
	if (health > 0) {
		return true;
	}
	else {
		return false;
	}
}
