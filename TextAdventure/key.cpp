#include "key.h"

Key::Key(std::string name, int weight, std::string description) : Item::Item(name,weight,description)
{
}

Key::~Key()
{

}

void Key::Use()
{
	std::cout << "You can not use that right now, maybe try the unlock command instead"<< std::endl;
}
