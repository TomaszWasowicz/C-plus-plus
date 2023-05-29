#include <iostream>
#include<cstddef>

void print(std::nullptr_t)
{
	std::cout << "in print std::nullptr_t\n";
}

void print(int*)
{
	std::cout << "in print int*\n";
}

int main()
{
	print(nullptr);   //print(std::nullptr_t

	int x{ 5 };
	int* ptr{ &x };

	print(ptr);    //print(int*)

	ptr = nullptr;
	print(ptr);			// print(int*) poniewaz ptr ma typ int*

	return 0;
}