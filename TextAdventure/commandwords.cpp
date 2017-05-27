// commandwords.cpp

#include "commandwords.h"

CommandWords::CommandWords()
{
	validCommands.push_back("go");
	validCommands.push_back("quit");
	validCommands.push_back("help");
	validCommands.push_back("look");
	validCommands.push_back("health");
	validCommands.push_back("backpack");
	validCommands.push_back("unlock");
	validCommands.push_back("pickup");
}

CommandWords::~CommandWords()
{

}

bool CommandWords::isCommand(std::string str)
{
	for (size_t i = 0; i < validCommands.size(); i++) {
		if (validCommands[i].compare(str) == 0) {
			return true;
		}
	}
	return false;
}
