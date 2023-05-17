#include <iostream>
#include <cstddef>     // for std::size_t

int main()
{
	std::cout << sizeof(int) << '\n';			//4 bytes

	//size_t - unsigned integral type, used to represent the size or length of objcects
	std::cout << sizeof(std::size_t) << '\n';	 // 8bytes

	return 0;
}