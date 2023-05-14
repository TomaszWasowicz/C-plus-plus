#include <iostream>
#include <string>

void printValue(std::string& y)
{
	std::cout << y << '\n';
}

int main()
{
	std::string x{ "Hello, world!" }; // x is a std::string

	printValue(x); //x is passed by reference into parameter y ( inexpensive )

	return 0;
}