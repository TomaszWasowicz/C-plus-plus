#include <iostream>

int main()  //64 bity system
{
	char const* charPtr{};//8
	int const* intPtr{}; // 8
	long int longIntPtr{}; //4
	long double longDoublePtr{};  //8

	std::cout << sizeof(charPtr) << sizeof(intPtr) << sizeof(longIntPtr) << sizeof(longDoublePtr);

	return 0;
}