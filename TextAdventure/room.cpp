#include "room.h"

Room::Room(std::string name, std::string desc)
{
	this->name = name;
	this->description = desc;

	int test = 10;
	items = new Inventory(test);
}

Room::~Room()
{
	delete items;
}

void Room::setExit(std::string direction, Room* neighbor)
{
	exits[direction] = neighbor;
	exitsStrings.push_back(direction);
}

Room* Room::getExit(std::string direction)
{
	if (exits.find(direction) != exits.end()) {
		return exits[direction];
	}
	return NULL;
}

std::string Room::GetName()
{
	return name;
}

std::string Room::getExitString()
{
	std::string returnString = "Exits: ";
	std::map<std::string,Room*>::iterator it = exits.begin();
	while (it != exits.end()) {
		returnString += it->first;
		returnString += "(" + exits[it->first]->GetName() + ")";
		returnString += " ";
		++it;
	}
	return returnString;
}

std::vector<std::string> Room::getExitsVector()
{
	return exitsStrings;
}

void Room::LockRoom(Key* key)
{
	lock = true;
	this->key = key;
}

std::string Room::GetKeyName()
{
	return this->key->GetName();
}

void Room::UnlockRoom(std::string keyName)
{
	if (this->key->GetName().compare(keyName) == 0) {
		lock = false;
	}
}

bool Room::CheckLock()
{
	return lock;
}

void Room::PlaceItem(Item* item)
{
	items->Add(item);
}

void Room::RemoveItem(std::string nameItem)
{
	items->Remove(nameItem);
}

Item* Room::GetItem(std::string nameItem)
{
	return items->GetItem(nameItem);
}

bool Room::ContainsItems()
{
	return items->ContainsItems();
}

void Room::PrintItems()
{
	items->PrintInventory();
}

void Room::PlaceZombie(Zombie* zombie)
{
	zombies.push_back(zombie);
	std::string zombieName = "zombie." + std::to_string(zombieCount);
	zombieCount++;
	zombie->GiveName(zombieName);
}

bool Room::ConatainsZombies()
{
	if (zombies.size() > 0) {
		return true;
	}
	return false;
}

void Room::PrintZombies()
{
	std::vector<Zombie*>::iterator it = zombies.begin();
	std::cout << "zombies: ";
	int num = 1;
	while (it != zombies.end()) {
		std::cout << (*it)->GetName() << (*it)->GetInfo();
		++it;
		num++;
		if (it == zombies.end()) {
			std::cout << std::endl;
		}
		else {
			std::cout << ", ";
		}
	}
}

void Room::ZombiesAttack(Player* player)
{
	std::vector<Zombie*>::iterator it = zombies.begin();
	while (it != zombies.end()) {
		(*it)->DoDamage(player);
		++it;
	}
}

void Room::AttackZombie(int damage, int hitAmount)
{
	std::vector<Zombie*>::iterator it = zombies.begin();
	int hits = 0;
	while (it != zombies.end() && hits < hitAmount) {
		(*it)->TakeDamage(damage);
		if (!(*it)->IsAlive()) {
			it = zombies.erase(it);
		}
		else {
			++it;
		}
		hits++;
	}
}
