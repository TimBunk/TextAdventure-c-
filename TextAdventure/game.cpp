#include <iostream>
#include <string>
#include <stdio.h>

#include "game.h"

Game::Game()
{
	ChangeColor();
	player = new Player(10,10);
	
	this->createRooms();
	this->CreateItems();

	player->ApplyDamage(0, false);
	player->AddItem(greenkey);
	player->AddItem(bandage);
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

	delete zombie;
	delete zombie2;
	delete zombie3;
}

void Game::ChangeColor()
{
	switch (color) {
		case 0:
			rlutil::setColor(rlutil::YELLOW);
			break;
		case 1:
			rlutil::setColor(rlutil::LIGHTGREEN);
	}
	color++;
	if (color > 1)
		color = 0;
}

void Game::createRooms()
{
	// create the rooms
	house = new Room("you're house", "inside you're own house");
	basement = new Room("you're basement", "in you're basement");
	garage = new Room("you're garage", "in you're garage");
	neighboursHouse = new Room("neighbours house", "inside you're neighbours house");
	willowStreet = new Room("Willowstreet-1", "on the Willowstreet");
	willowStreet2 = new Room("Willowstreet-2", "on the second part of the Willowstreet");
	playground = new Room("playground", "on the playground");
	shed = new Room("old shed", "inside a old shed");
	ridgeRoad = new Room("Ridgeroad", "on the Ridgeroad");
	mainStreet = new Room("mainStreet-1", "on the Mainstreet");
	mainStreet2 = new Room("mainStreet-2", "on the second part of the Mainstreet");
	shore = new Room("shore", "on the shore");
	weaponStore = new Room("weapon store", "inside of the weaponStore");
	parkingArea = new Room("parking area", "on the parking area");
	park = new Room("park", "in the park");
	abandondedHouse = new Room("abandonded house", "inside a abandond house");
	pharmacy = new Room("pharmacy", "inside a pharmacy");
	backyard = new Room("backyard", "in the backyard of the abandond house");
	sea = new Room("sea", "in front of the sea");

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
	willowStreet->setExit("south", house);
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

	// Create zombies
	zombie = new Zombie("Mr.zombie", 1, 2, true);
	zombie2 = new Zombie("Giant zombie", 2, 1, true);
	zombie3 = new Zombie("Midget zombie", 1, 1, false);
	willowStreet->PlaceZombie(zombie);
	willowStreet->PlaceZombie(zombie2);
	willowStreet->PlaceZombie(zombie3);
	
	this->player->setCurrentRoom(house);  // start game outside
}

void Game::CreateItems()
{
	// create items
	greenkey = new Key("greenkey", 6, "used to open doors");
	garage->LockRoom(greenkey);

	bluekey = new Key("bluekey", 1, "used to open doors");
	house->PlaceItem(bluekey);

	bandage = new Medicine("bandage", 1, "used to stop bleeding", 2, true);
}

void Game::play()
{
	this->printWelcome();

	bool finished = false;
	while ( !finished ) {
		ChangeColor();
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
	} else if (commandWord.compare("use") == 0) {
		player->UseItem(cmd);
	}
	return wantToQuit;
}

void Game::printWelcome()
{
	std::cout << std::endl;
	std::cout << "Welcome to EscapeTheZombies!" << std::endl;
	std::cout << "EscapeTheZombies is a new exciting text adventure." << std::endl;
	
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
