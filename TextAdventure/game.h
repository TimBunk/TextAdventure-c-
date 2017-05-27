// game.h

#ifndef GAME_H
#define GAME_H

#include <string>

#include "parser.h"
#include "command.h"
#include "room.h"
#include "player.h"
#include "item.h"
#include "key.h"
#include "rlutil.h"

class Game
{
public:
	Game();
	virtual ~Game();
	void play();

private:
	void createRooms();
	void CreateItems();
	bool processCommand(Command cmd);
	void printWelcome();
	void printHelp();

	Player* player;
	Parser parser;

	//list with rooms
	Room* outside;
	Room* theatre;
	Room* pub;
	Room* lab;
	Room* office;
	Room* basement;

	//list with items
	Key* greenkey;
	Key* bluekey;
	Item* apple;
	Item* mobile;
};

#endif /* GAME_H */
