#include <iostream>

void printInt(int x)
{
	std::cout << x << '\n';
}



int main()
{
	printInt(2);	

	short s(3);		// short int to int

	printInt('a');	// char to int

	printInt(true);  // bool to int





	return 0;
}