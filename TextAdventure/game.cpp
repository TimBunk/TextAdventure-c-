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
	player->AddItem(*bandage);
}

Game::~Game()
{
	delete player;

	delete house;
	delete basement;
	delete garage;
	delete neighboursHouse;
	delete willowStreet;
	delete willowStreet2;
	delete playground;
	delete shed;
	delete ridgeRoad;
	delete mainStreet;
	delete mainStreet2;
	delete shore;
	delete weaponStore;
	delete parkingArea;
	delete park;
	delete abandondedHouse;
	delete pharmacy;
	delete backyard;
	delete sea;

	delete greenkey;
	delete bluekey;
	delete bandage;
}

void Game::createRooms()
{
	// create the rooms
	house = new Room("inside you're own house");
	basement = new Room("in you're basement");
	garage = new Room("in you're garage");
	neighboursHouse = new Room("inside you're neighbours house");
	willowStreet = new Room("on the Willowstreet");
	willowStreet2 = new Room("on the second part of the Willowstreet");
	playground = new Room("on the playground");
	shed = new Room("inside a old shed");
	ridgeRoad = new Room("on the Ridgeroad");
	mainStreet = new Room("on the Mainstreet");
	mainStreet2 = new Room("on the second part of the Mainstreet");
	shore = new Room("on the shore");
	weaponStore = new Room("inside of the weaponStore");
	parkingArea = new Room("on the parking area");
	park = new Room("in the park");
	abandondedHouse = new Room("inside a abandond house");
	pharmacy = new Room("inside a pharmacy");
	backyard = new Room("in the backyard of the abandond house");
	sea = new Room("in front of the sea");

	// initialise room exits
	house->setExit("north", willowStreet);
	house->setExit("east", garage);
	house->setExit("down", basement);
	
	basement->setExit("up", house);
	
	garage->setExit("north", willowStreet2);
	garage->setExit("west", house);

	neighboursHouse->setExit("east", willowStreet);

	willowStreet->setExit("north", ridgeRoad);
	willowStreet->setExit("east", willowStreet2);
	willowStreet->setExit("west", neighboursHouse);
	
	willowStreet2->setExit("east", playground);
	willowStreet2->setExit("south", garage);
	willowStreet2->setExit("west", willowStreet);

	playground->setExit("north", mainStreet);
	playground->setExit("west", willowStreet2);

	shed->setExit("north", mainStreet2);

	ridgeRoad->setExit("north", parkingArea);
	ridgeRoad->setExit("south", willowStreet);

	mainStreet->setExit("north", abandondedHouse);
	mainStreet->setExit("east", mainStreet2);
	mainStreet->setExit("south", playground);
	
	mainStreet2->setExit("east", shore);
	mainStreet2->setExit("south", shed);
	mainStreet2->setExit("west", mainStreet);
	
	shore->setExit("west", mainStreet2);

	weaponStore->setExit("east", parkingArea);

	parkingArea->setExit("north", pharmacy);
	parkingArea->setExit("east", park);
	parkingArea->setExit("south", ridgeRoad);
	parkingArea->setExit("west", weaponStore);
	
	park->setExit("east", abandondedHouse);
	park->setExit("west", parkingArea);

	abandondedHouse->setExit("north", backyard);
	abandondedHouse->setExit("south", mainStreet);
	abandondedHouse->setExit("west", park);

	pharmacy->setExit("south", parkingArea);

	backyard->setExit("north", sea);
	backyard->setExit("south", abandondedHouse);

	sea->setExit("south", backyard);
	
	this->player->setCurrentRoom(house);  // start game outside
}

void Game::CreateItems()
{
	// create items
	greenkey = new Key("greenkey", 6);
	garage->LockRoom(greenkey);
	bluekey = new Key("bluekey", 1);
	std::cout << "Adress of bluekey: " << bluekey << std::endl;
	house->PlaceItem(bluekey);
	
	apple = new Item("apple", 1);
	std::cout << "Adress of apple: " << apple << std::endl;
	house->PlaceItem(apple);
	std::cout << house->GetItem("apple") << std::endl;
	house->PrintItems();
	house->RemoveItem("apple");
	house->PrintItems();
	mobile = new Item("mobile", 2);
	//garage->PlaceItem(mobile);
	bandage = new Medicine("bandage", 1, 2);
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
	std::cout << "Welcome to EscapeTheZombies!" << std::endl;
	std::cout << "EscapeTheZombies is a new, text adventure game." << std::endl;
	
	std::cout << std::endl;
	std::cout << "It is early in the morning you just woke up and hear someone knocking really loudly on you're front door." << std::endl;
	std::cout << "You look through the window and see a zombie standing in front of you're door!" << std::endl;
	std::cout << "Rather quikly you find out that there is a zombie apocalypse going on." << std::endl;
	std::cout << "You're goal is to escape from the zombies." << std::endl;

	std::cout << std::endl;
	std::cout << "NOTE! When confronting a zombie you have to kill him, otherwise the zombie will attack you and you take damage and start bleeding!" << std::endl;
	std::cout << "Zombies will respawn after you travelled 3 times to another location" << std::endl;

	std::cout << "Type 'help' if you need help." << std::endl;
	std::cout << std::endl;
	player->describeRoom();
}

void Game::printHelp()
{
	std::cout << "You are lost. You are alone. You wander" << std::endl;
	std::cout << "around in Groningen." << std::endl;
	std::cout << std::endl;
	std::cout << "Your command words are:" << std::endl;
	parser.showCommands();
}
