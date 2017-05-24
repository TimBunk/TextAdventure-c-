#include "key.h"

Key::Key(std::string name, int weight) : Item::Item(name,weight)
{
	this->roomName = roomName;
}

Key::~Key()
{

}