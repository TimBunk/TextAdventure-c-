#include <string>

class Item
{
public:
	Item(std::string name, int weight);
	~Item();
	std::string GetName();
	int GetWeight();

private:
	std::string name;
	int weight;

protected:

};