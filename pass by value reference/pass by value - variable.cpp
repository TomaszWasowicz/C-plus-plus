#include <iostream>

void printValue(int y)
{
	std::cout << y << '\n';
}

int main()
{
	int x{ 2 };

	printValue(x); //pass by value

	return 0;
}