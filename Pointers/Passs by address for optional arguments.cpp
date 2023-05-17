#include <iostream>
#include <string>

void greet(std::string* name = nullptr)
{
	std::cout << "Hello ";
	std::cout << (name ? *name : "guest") << '\n';
}

int main()
{
	greet();					//nie wiemy kogo witamy

	std::string joe{ "Joe" };
	greet(&joe);				//wiemy kogo witamy 
}