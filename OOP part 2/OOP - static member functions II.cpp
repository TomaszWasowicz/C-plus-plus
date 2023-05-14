#include <iostream>

class IDGenerator
{
private:
	static int s_nextID; //declaration for a static member

public:
	static int getNextID();
};
	
int IDGenerator::s_nextID{ 1 };  // definition of a static member

int IDGenerator::getNextID() { return s_nextID++; }		// definition of a static function

int main()
{

	for (int count{ 0 }; count < 5; ++count)
		std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';


	return 0;
}
	
	
