#include <iostream>
#include <optional>
#include <string>

void greet(std::optional<std::string> name = std::nullopt)  //copy of the std::string
{
	std::cout << "Hello ";
	std::cout << (name ? *name : "guest") << '\n';
}

int main()
{
	greet();	// we don't know who the user is yet

	greet("Joe");	// we know the user is joe, can even pass is an rvalue

	return 0;
}