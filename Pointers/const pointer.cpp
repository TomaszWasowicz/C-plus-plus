#include <iostream>

int main()
{
	int value{ 5 };						//non-const int

	const int* ptr{ &value };			// ptr points to a "const int value"

	//*ptr = 7; - nie mozna

	int* const ptr{ &value };			// const ptr points to a int value

	//*ptr = 7; - nie mozna


	const int value2{ 6 };

	const int* ptr2{ &value2 };			//ptr point to a "const int value"
	const int* const ptr2{ &value2 };	//const ptr points to a const inst value





	return 0;
}