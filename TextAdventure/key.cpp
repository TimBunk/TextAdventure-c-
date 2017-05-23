#include "key.h"

/*Key::Key(std::string name, int weight)// : Item(name, weight)
{

}*/

Key::Key(Room keyRoom, std::string name, int weight) : Item::Item(name,weight)
{
	this->keyRoom = &keyRoom;
}

Key::~Key()
{

}

Room Key::GetKeyRoom()
{
	return *keyRoom;
}