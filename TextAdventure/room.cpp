#include "room.h"
#include "player.h"

Room::Room(std::string name, std::string desc)
{
	this->name = name;
	this->description = desc;

	items = new Inventory(999);
}

Room::~Room()
{
	delete items;
}

void Room::SetToFinalRoom(std::string desc)
{
	finalRoomDesc = desc;
	finalRoom = true;
}

bool Room::CheckIfFinalRoom()
{
	return finalRoom;
}

void Room::PrintFinalRoom()
{
	std::cout << finalRoomDesc << std::endl;
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
	int totalDamage = 0;
	bool bleed = false;
	while (it != zombies.end()) {
		totalDamage += (*it)->DoDamage();
		if (!bleed) {
			bleed = (*it)->AppliesBleed();
		}
		++it;
	}
	if (zombies.size() > 1) {
		std::cout << "you got attacked by the zombies" << std::endl;
	}
	else {
		std::cout << "you got attacked by the zombie" << std::endl;
	}
	player->ApplyDamage(totalDamage, bleed);
}

void Room::AttackZombie(int damage, int hitAmount)
{
	std::vector<Zombie*>::iterator it = zombies.begin();
	int hits = 0;
	while (it != zombies.end() && hits < hitAmount) {
		(*it)->TakeDamage(damage);
		if (!(*it)->IsAlive()) {
			std::cout << "You killed " << (*it)->GetName();
			deadZombies.push_back((*it));
			it = zombies.erase(it);
		}
		else {
			std::cout << (*it)->GetName() << " took " << damage << " damage";
			++it;
		}
		std::cout << "  ";
		hits++;
	}
	std::cout << std::endl;
}

void Room::UpdateZombies()
{
	if (deadZombies.size() <= 0) {
		return;
	}
	std::vector<Zombie*>::iterator it = deadZombies.begin();
	while (it != deadZombies.end()) {
		if ((*it)->RespawnAvailable()) {
			RespawnZombie((*it));
			it = deadZombies.erase(it);
		}
		else {
			(*it)->IncreaseDeathTime();
			++it;
		}
	}
}

void Room::RespawnZombie(Zombie* zombie)
{
	zombie->Respawned();
	zombies.push_back(zombie);
}
