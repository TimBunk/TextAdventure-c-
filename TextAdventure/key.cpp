#include "key.h"

/*Key::Key(std::string name, int weight)// : Item(name, weight)
{

}*/

Key::Key(std::string name, int weight) : Item::Item(name,weight)
{
	std::cout << "test" << std::endl;
}

Key::~Key()
{
}

void Key::printff()
{
	std::cout << "print" << std::endl;
}
