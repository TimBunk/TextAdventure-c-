#include "weapon.h"

Weapon::Weapon(std::string name, int weight, std::string description) : Item::Item(name,weight,description)
{

}

Weapon::~Weapon()
{
}

void Weapon::Use()
{
}
