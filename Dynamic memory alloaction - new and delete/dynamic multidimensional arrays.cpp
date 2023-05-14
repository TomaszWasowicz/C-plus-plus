#include <iostream>

int main()
{

	int** array{ new int* [10] };
	for (int count = 0; count < 10; ++count)
		array[count] = new int[count + 1];

	for (int count = 0; count < 10; ++count)
		delete[]array[count];
	delete[]array;



	return 0;
}