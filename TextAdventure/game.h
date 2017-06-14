#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "parser.h"
#include "command.h"
#include "room.h"
#include "player.h"
#include "item.h"
#include "key.h"
#include "medicine.h"
#include "zombie.h"
#include "weapon.h"
#include "rlutil.h"

class Game
{
public:
	Game();
	virtual ~Game();
	void play();

private:
	void ChangeColor();
	int color = 0;
	void createRooms();
	void CreateItems();
	void UpdateRooms();
	bool processCommand(Command cmd);
	void printWelcome();
	void printHelp();

	Player* player;
	Parser parser;

	//list with rooms
	//std::vector
	
	Room* house;
	Room* basement;
	Room* garage;
	Room* neighboursHouse;
	Room* willowStreet;
	Room* willowStreet2;
	Room* playground;
	Room* shed;
	Room* ridgeRoad;
	Room* mainStreet;
	Room* mainStreet2;
	Room* shore;
	Room* weaponStore;
	Room* parkingArea;
	Room* park;
	Room* abandondedHouse;
	Room* pharmacy;
	Room* backyard;
	Room* sea;
	std::vector<Room*> rooms;

	//list with items
	Key* rustyKey;
	Key* weaponStoreKey;
	Medicine* bandage;
	Medicine* firstAidKit;
	Weapon* axe;
	Weapon* baseballBat;
	Weapon* handgun;
	Weapon* flamethrower;
	Weapon* bazooka;

	//list with zombies
	Zombie* zombie;
	Zombie* zombie2;
	Zombie* zombie3;
};

#endif
