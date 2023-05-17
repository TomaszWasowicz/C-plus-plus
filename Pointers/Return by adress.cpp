#include <iostream>

int* fun(int size)
{
	int* p = new int[size];
	for (int i = 0; i < size; i++)
	{
		p[i] = i + 1;
	}
	return p;
}

int main()
{
	int* ptr = fun(5);
	for (int j = 0; j < 5; j++)
	{
		std::cout << ptr[j] << '\n';
	}

	return 0;
}