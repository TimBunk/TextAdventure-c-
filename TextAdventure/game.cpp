// game.cpp

#include <iostream>
#include <string>
#include <stdio.h>

#include "game.h"

Game::Game()
{
	rlutil::setColor(rlutil::YELLOW);
	player = new Player();
	
	this->createRooms();
	this->CreateItems();

	player->AddItem(*greenkey);
	//player->AddItem(*bluekey);
}

Game::~Game()
{
	delete player;

	delete outside;
	delete theatre;
	delete pub;
	delete lab;
	delete office;
	delete basement;

	delete greenkey;
	delete bluekey;
}

void Game::createRooms()
{
	// create the rooms
	outside = new Room("outside the main entrance of the university");
	theatre = new Room("in a lecture theatre");
	pub = new Room("in the campus pub");
	lab = new Room("in a computing lab");
	office = new Room("in the computing admin office");
	basement = new Room("in the basement of the pub");

	// initialise room exits
	outside->setExit("east", theatre);
	outside->setExit("south", lab);
	outside->setExit("west", pub);

	theatre->setExit("west", outside);

	pub->setExit("east", outside);
	pub->setExit("down", basement);

	basement->setExit("up", pub);

	lab->setExit("north", outside);
	lab->setExit("east", office);

	office->setExit("west", lab);
	this->player->setCurrentRoom(outside);  // start game outside
}

void Game::CreateItems()
{
	// create items
	greenkey = new Key("greenkey", 6);
	theatre->LockRoom(greenkey);
	bluekey = new Key("bluekey", 1);
	pub->PlaceItem(*bluekey);
	apple = new Item("apple", 1);
	pub->PlaceItem(*apple);
	mobile = new Item("mobile", 2);
	pub->PlaceItem(*mobile);
}

void Game::play()
{
	this->printWelcome();

	bool finished = false;
	while ( !finished ) {
		Command command = parser.getCommand();
		finished = processCommand(command);
		if (!finished && !player->IsAlive()) {
			finished = true;
		}
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
		wantToQuit = true;
	} else if (commandWord.compare("look") == 0) {
		player->describeRoom();
	} else if (commandWord.compare("health") == 0) {
		player->PrintHealth();
	} else if (commandWord.compare("backpack") == 0) {
		player->PrintBackpackInfo();
	} else if (commandWord.compare("unlock") == 0) {
		player->UnlockRoom(cmd);
	} else if (commandWord.compare("pickup") == 0) {
		player->PickUp(cmd);
	} else if (commandWord.compare("drop") == 0) {
		player->DropItem(cmd);
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
	player->describeRoom();
}

void Game::printHelp()
{
	std::cout << "You are lost. You are alone. You wander" << std::endl;
	std::cout << "around at the university." << std::endl;
	std::cout << std::endl;
	std::cout << "Your command words are:" << std::endl;
	parser.showCommands();
}
