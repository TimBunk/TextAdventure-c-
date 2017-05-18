// game.h

#ifndef GAME_H
#define GAME_H

#include <string>

#include "parser.h"
#include "command.h"
#include "room.h"
#include "player.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void play();

private:
	void createRooms();
	bool processCommand(Command cmd);
	void printWelcome();
	void printHelp();

	player* player;
	Parser parser;

	Room* outside;
	Room* theatre;
	Room* pub;
	Room* lab;
	Room* office;
};

#endif /* GAME_H */
