#include <iostream>

int main()
{
	char* chPtr{};
	int* iPtr{};
	long double ldPtr{};

	std::cout << sizeof(chPtr) << '\n';			//4 bytes in 32 bit system , 8 bytes in 64 bit system
	std::cout << sizeof(iPtr) << '\n';			//4 bytes in 32 bit system , 8 bytes in 64 bit system
	std::cout << sizeof(ldPtr) << '\n';			//4 bytes in 32 bit system , 8 bytes in 64 bit system

	return 0;
}