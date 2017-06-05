#include "player.h"


Player::Player(int health, int backpackCapacity)
{
	this->maxHealth = health;
	this->health = health;
	backpack = new Backpack(backpackCapacity);
}

Player::~Player()
{
	delete backpack;
}

void Player::setCurrentRoom(Room *room)
{
	currentRoom = room;
}

void Player::describeRoom()
{
	std::cout << currentRoom->getShortDescription() << std::endl;
	if (currentRoom->ContainsItems()) {
		std::cout << "You see some items lying around : ";
		currentRoom->PrintItems();
	}
	std::cout << currentRoom->getExitString() << std::endl;
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
	else if (nextRoom->CheckLock()) {
		std::cout << "This door is locked, it requires a " << nextRoom->GetKeyName() << std::endl;
	}
	else {
		currentRoom = nextRoom;
		if (bleeding == true) {
			std::cout << "You are bleeding" << std::endl;
			ApplyDamage(1, false);
		}
		describeRoom();
	}
}

void Player::UnlockRoom(Command cmd)
{
	if (!cmd.hasSecondWord()) {
		// if there is no second word, we don't know what to unlock...
		std::cout << "Unlock what?" << std::endl;
		return;
	}

	std::string direction = cmd.getSecondWord();

	Room* nextRoom = currentRoom->getExit(direction);

	if (nextRoom == NULL) {
		std::cout << "There is no door!" << std::endl;
	}
	else if (nextRoom->CheckLock()) {
		Item* key = backpack->GetItem(nextRoom->GetKeyName());
		if (key == NULL) {
			std::cout << "This door requires a " << nextRoom->GetKeyName() << std::endl;
		}
		else {
			nextRoom->UnlockRoom(key->GetName());
			std::cout << " but the " << key->GetName() <<" broke" << std::endl;
			backpack->Remove(key->GetName());
		}
	}
	else {
		std::cout << "This door is already unlocked" << std::endl;
	}
}

void Player::PrintHealth()
{
	std::cout << health << "/"  << maxHealth << std::endl;
}

void Player::ApplyDamage(int amount, bool startsBleeding)
{
	if (!this->bleeding && startsBleeding) {
		this->bleeding = true;
		std::cout << "You got hurt and started bleeding" << std::endl;
	} 
	if (amount <= 0) {
		return;
	}
	if (amount > health) {
		amount = health;
	}
	health -= amount;
	std::cout << "You took " << amount << " damage, you're current health is now ";
	PrintHealth();
}

void Player::ApplyHeal(int amount, bool stopsBleeding)
{
	if (this->bleeding && stopsBleeding) {
		this->bleeding = false;
		std::cout << "You stopped the bleeding" << std::endl;
	}
	if (amount <= 0 || health >= maxHealth) {
		return;
	}
	else if (health + amount > maxHealth) {
		amount = maxHealth - health;
	}
	health += amount;
	std::cout << "You healed for " << amount << " , you're current health is now ";
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

void Player::PrintBackpackInfo()
{
	backpack->PrintInventory();
}

void Player::AddItem(Item* item)
{
	backpack->Add(item);
}

void Player::DropItem(Command cmd)
{
	if (!cmd.hasSecondWord()) {
		// if there is no second word, we don't know what to drop...
		std::cout << "What do you want to drop?" << std::endl;
		return;
	}

	std::string nameItem = cmd.getSecondWord();
	Item* item = backpack->GetItem(nameItem);

	if (item == NULL) {
		std::cout << "'" << nameItem << "'" << " not found" << std::endl;
	}
	else {
		currentRoom->PlaceItem(item);
		std::cout << "You dropped the " << item->GetName() << std::endl;
		backpack->Remove(item->GetName());
	}
}

void Player::PickUp(Command cmd)
{
	if (!cmd.hasSecondWord()) {
		// if there is no second word, we don't know what to pickup...
		std::cout << "What do you want to pickup?" << std::endl;
		return;
	}

	std::string nameItem = cmd.getSecondWord();
	Item* item = currentRoom->GetItem(nameItem);

	if (item == NULL) {
		std::cout << "'" << nameItem << "'" << " not found" << std::endl;
	}
	else if (backpack->GetCurrentWeight() + item->GetWeight() > backpack->GetCapacity()) {
		backpack->PrintOverCapacity(item);
	}
	else {
		backpack->Add(currentRoom->GetItem(item->GetName()));
		currentRoom->RemoveItem(item->GetName());
	}
}

void Player::UseItem(Command cmd)
{
	if (!cmd.hasSecondWord()) {
		// if there is no second word, we don't know what to pickup...
		std::cout << "What item do you want to use?" << std::endl;
		return;
	}

	std::string nameItem = cmd.getSecondWord();
	Item* item = backpack->GetItem(nameItem);

	if (item == NULL) {
		std::cout << "'" << nameItem << "'" << " not found" << std::endl;
	}
	else {
		// CHECK IF ITEM IS A MEDICINE
		if (dynamic_cast<Medicine*>(item) != NULL) {
			Medicine* medicine = dynamic_cast<Medicine*>(item);
			medicine->Use(this);
			std::cout << "Removed " << medicine->GetName() << " from inventory" << std::endl;
			backpack->Remove(medicine->GetName());
		}
		// CHECK IF ITEM IS A KEY
		else if (dynamic_cast<Key*>(item) != NULL) {
			Key* key = dynamic_cast<Key*>(item);
			key->Use();
		}
	}
}
