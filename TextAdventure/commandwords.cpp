// commandwords.cpp

#include "commandwords.h"

CommandWords::CommandWords()
{
	validCommands.push_back("go");
	validCommands.push_back("quit");
	validCommands.push_back("help");
	validCommands.push_back("look");
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
