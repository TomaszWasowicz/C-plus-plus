#include <iostream>
#include <string>

const std::string& firstAlphabetical(const std::string& a, const std::string& b)
{
	return (a < b) ? a : b;
}

int main()
{
	std::string hello{ "Hello" };
	std::string world{ "World" };

	std::cout << firstAlphabetical(hello, world);

	return 0;
}