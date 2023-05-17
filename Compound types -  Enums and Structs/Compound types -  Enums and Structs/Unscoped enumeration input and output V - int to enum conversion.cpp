#include <iostream>

enum Pet
{
	cat,
	dog,
	pig,
	whale,
};

int main()
{
	Pet pet{ static_cast<Pet>(2) };    //convert 2 - an integer, to a Pet - an enum

	std::cout << pet << '\n';

	pet = static_cast<Pet>(3);			// pig changed to a whale

	std::cout << pet << '\n';



	return 0;
}