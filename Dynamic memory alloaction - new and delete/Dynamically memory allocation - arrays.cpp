#include <iostream>

int main()
{
	std::cout << "Enter a positive integer: ";
	int length{};
	std::cin >> length;

	int* array{ new int[length] {} };

	std::cout << "I have just allocated an array of integers length: "
		<< length << '\n';
	
	array[0] = 5;
	delete[] array;






	return 0;
}