// game.h

#ifndef GAME_H
#define GAME_H

#include <string>

#include "parser.h"
#include "command.h"
#include "room.h"
#include "player.h"
#include "item.h"
#include "rlutil.h"

class Game
{
public:
	Game();
	virtual ~Game();
	void play();
	Item* apple;

private:
	void createRooms();
	bool processCommand(Command cmd);
	void printWelcome();
	void printHelp();

	Player* player;
	Parser parser;

	Room* outside;
	Room* theatre;
	Room* pub;
	Room* lab;
	Room* office;
	Room* basement;
};

#endif /* GAME_H */
