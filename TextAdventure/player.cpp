#include "player.h"


Player::Player(int health, int backpackCapacity)
{
	this->maxHealth = health;
	this->health = health;
	backpack = new Inventory(backpackCapacity);
}

Player::~Player()
{
	delete backpack;
}

void Player::setCurrentRoom(Room* room)
{
	currentRoom = room;
}

void Player::describeRoom()
{
	std::cout << currentRoom->getShortDescription() << std::endl;
	if (currentRoom->ContainsItems()) {
		std::cout << "You see some items lying around : " << std::endl;
		currentRoom->PrintItems();
	}
	if (currentRoom->ConatainsZombies()) {
		currentRoom->PrintZombies();
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
		if (bleeding == true) {
			std::cout << "You are bleeding" << std::endl;
			ApplyDamage(1, false);
		}
		if (currentRoom->ConatainsZombies() && IsAlive()) {
			currentRoom->ZombiesAttack(this);
		}
		if (!IsAlive()) {
			return;
		}

		currentRoom = nextRoom;

		if (currentRoom->CheckIfFinalRoom()) {
			reachedFinalRoom = true;
			currentRoom->PrintFinalRoom();
		}
		else {
			describeRoom();
		}
	}
}

bool Player::ReachedFinalRoom()
{
	return reachedFinalRoom;
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
	std::cout << "inventory Capacity = " << backpack->GetCurrentWeight() << "/" << backpack->GetCapacity() << std::endl;
	backpack->PrintInventory();
}

void Player::AddItem(Item* item)
{
	if (item->GetWeight() + backpack->GetCurrentWeight() <= backpack->GetCapacity()) {
		backpack->Add(item);
		std::cout << "added " << item->GetName() << " to your backpack"<< std::endl;
		std::cout << "inventory Capacity = " << backpack->GetCurrentWeight() << "/" << backpack->GetCapacity() << std::endl;
	}
	else {
		std::cout << "could not add " << item->GetName() << " because your backpack is full" << std::endl;
	}
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
		backpack->Remove(item->GetName());
		std::cout << "You dropped the " << item->GetName() << std::endl;
		std::cout << "inventory Capacity = " << backpack->GetCurrentWeight() << "/" << backpack->GetCapacity() << std::endl;
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
		std::cout << "there is no more room in your backpack" << std::endl;
		std::cout << "inventory Capacity = " << backpack->GetCurrentWeight() << "/" << backpack->GetCapacity() << std::endl;
	}
	else {
		backpack->Add(currentRoom->GetItem(item->GetName()));
		currentRoom->RemoveItem(item->GetName());
		std::cout << "added " << item->GetName() << " to backpack" << std::endl;
		std::cout << "inventory Capacity = " << backpack->GetCurrentWeight() << "/" << backpack->GetCapacity() << std::endl;
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
			if (health < maxHealth && medicine->Healing()) {
				medicine->Use(this);
				std::cout << "Removed " << medicine->GetName() << " from inventory" << std::endl;
				backpack->Remove(medicine->GetName());
			}
			else if (bleeding && medicine->StopsBleeding()) {
				medicine->Use(this);
				std::cout << "Removed " << medicine->GetName() << " from inventory" << std::endl;
				backpack->Remove(medicine->GetName());
			}
			else {
				std::cout << "You can not use that right now" << std::endl;
			}
		}
		// CHECK IF ITEM IS A KEY
		else if (dynamic_cast<Key*>(item) != NULL) {
			Key* key = dynamic_cast<Key*>(item);
			key->Use(currentRoom);
			if (key->Succeeded().compare("") != 0) {
				std::cout << "you unlocked the room to your " << key->Succeeded() << " but the " << key->GetName() << " broke" << std::endl;
				backpack->Remove(key->GetName());
			}
			else {
				std::cout << "The key doesn't seem to fit any of the doors" << std::endl;
			}
		}
		// CHECK IF ITEM IS A WEAPON
		else if (dynamic_cast<Weapon*>(item) != NULL) {
			Weapon* weapon = dynamic_cast<Weapon*>(item);
			if (currentRoom->ConatainsZombies()) {
				weapon->Use(currentRoom);
				if (!weapon->IsAlive()) {
					std::cout << "but your " << weapon->GetName() << " broke" << std::endl;
					backpack->Remove(weapon->GetName());
				}
				if (currentRoom->ConatainsZombies()) {
					std::cout << std::endl;
					std::cout << "remaining ";
					currentRoom->PrintZombies();
				}
			}
			else {
				std::cout << "Better not use it if i don't need to" << std::endl;
			}
		}
	}
}
