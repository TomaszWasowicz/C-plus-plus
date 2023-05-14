#include <iostream>
#include <string>

void printValue(std::string y)
{
	std::cout << y << '\n';
}

int main()
{
	std::string x{ "Hello, world!"}; // x is a std::string

	printValue(x); //x is passed by value ( copied ) into parameter y ( expensive )

	return 0;
}