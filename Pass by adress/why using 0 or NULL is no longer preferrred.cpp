#include <iostream>
#include <cstddef> //for NULL

void print(int x)
{
	std::cout << "print(int): " << x << '\n';
}

void print(int* ptr)
{
	std::cout << "print(int*): " << (ptr ? "non-null\n" : "nulll\n");
}

int main()
{
	int x{ 5 };
	int* ptr{ &x };

	print(ptr);		//print( int* ptr ) - because it matches a pointer
	print(0);		// print(int)

	print(NULL);	//print(int)

	print(nullptr); //print( int* ptr ) - because it matches a pointer


	return 0;
}