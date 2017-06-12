#ifndef GAME_H
#define GAME_H

#include <string>
#include <array>

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
	bool processCommand(Command cmd);
	void printWelcome();
	void printHelp();

	Player* player;
	Parser parser;

	//list with rooms
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


	//list with items
	Key* greenkey;
	Key* bluekey;
	Medicine* bandage;
	Weapon* axe;

	//list with zombies
	Zombie* zombie;
	Zombie* zombie2;
	Zombie* zombie3;
};

#endif
