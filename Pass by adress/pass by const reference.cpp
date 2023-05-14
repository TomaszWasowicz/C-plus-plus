#include <iostream>

void printByValue(int val) //pass by value, copy the value
{
	std::cout << val << '\n';
}

void printByReference(const int& ref) // pass by reference
{
	std::cout << ref << '\n';
}

void printByAdress(const int* ptr) // pass by adress
{
	std::cout << *ptr << '\n';
}

int main()
{
	printByValue(5);
	printByReference(5);
	
	int const ptr{5};
	printByAdress(&ptr); // error, can't take address of r-value

	return 0;
}
