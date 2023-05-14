#include <iostream>

int main()
{
	const int& ref{ 5 }; // 5 is an rvalue
	std::cout << ref;

	return 0;
}