// game.cpp

#include <iostream>
#include <string>

#include "game.h"

Game::Game()
{
	this->createRooms();
}

Game::~Game()
{
	delete outside;
	delete theatre;
	delete pub;
	delete lab;
	delete office;
}

void Game::createRooms()
{
	// create the rooms
	outside = new Room("outside the main entrance of the university");
	theatre = new Room("in a lecture theatre");
	pub = new Room("in the campus pub");
	lab = new Room("in a computing lab");
	office = new Room("in the computing admin office");

	// initialise room exits
	outside->setExit("east", theatre);
	outside->setExit("south", lab);
	outside->setExit("west", pub);

	theatre->setExit("west", outside);

	pub->setExit("east", outside);

	lab->setExit("north", outside);
	lab->setExit("east", office);

	office->setExit("west", lab);
	std::cout << "test" << std::endl;
	player = new Player();
	this->player->setCurrentRoom(outside);  // start game outside
	std::cout << "test" << std::endl;
}

void Game::play()
{
	this->printWelcome();

	bool finished = false;
	while ( !finished ) {
		Command command = parser.getCommand();
		finished = processCommand(command);
	}
	std::cout << "Thank you for playing. Goodbye!" << std::endl;
}

bool Game::processCommand(Command cmd)
{
	bool wantToQuit = false;

	if(cmd.isUnknown()) {
		std::cout << "I don't know what you mean..." << std::endl;
		return false;
	}

	std::string commandWord = cmd.getCommandWord();

	if (commandWord.compare("help") == 0) {
		this->printHelp();
	} else if (commandWord.compare("go") == 0) {
		this->player->goRoom(cmd);
	} else if (commandWord.compare("quit") == 0) {
		//wantToQuit = quit(command);
		wantToQuit = true;
	}
	else if (commandWord.compare("look") == 0) {
		player->describeRoom();
	}

	return wantToQuit;
}

void Game::printWelcome()
{
	std::cout << std::endl;
	std::cout << "Welcome to Zuul!" << std::endl;
	std::cout << "Zuul is a new, incredibly boring adventure game." << std::endl;
	std::cout << "Type 'help' if you need help." << std::endl;
	std::cout << std::endl;
	//player->describeRoom();
}

void Game::printHelp()
{
	std::cout << "You are lost. You are alone. You wander" << std::endl;
	std::cout << "around at the university." << std::endl;
	std::cout << std::endl;
	std::cout << "Your command words are:" << std::endl;
	parser.showCommands();
}
