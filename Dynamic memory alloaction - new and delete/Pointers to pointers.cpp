#include <iostream>

int main()
{
	int value{ 5 };

	int* ptr{ &value };

	std::cout << *ptr << '\n';

	int** ptrptr{ &ptr };
	std::cout << **ptrptr << '\n';


	// int** ptrptr {&value};    nie dzia³a
	int** ptrptr{ nullptr };  // pointer to a pointer can be set to null


	return 0;
}