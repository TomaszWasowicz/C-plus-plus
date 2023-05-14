#include <iostream>

int main()
{
	int* ptr{ new int{} };
	int* otherPtr{ ptr };

	delete ptr;			//kazdy wskaznik musi byc usuwany i zerowany
	ptr = nullptr;

	delete otherPtr;
	otherPtr = nullptr;

	int* value{ new (std::nothrow) int }; // wartosc na nullptr jesli
											//alokacja pamieci zawiedzie




	return 0;
}