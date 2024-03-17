#include <array>
#include <iostream>

int main() {

	//The length and indices of std::array have type size_type, which is always std::size_t

	// returns length as type `size_type` (alias for `std::size_t`)
	constexpr std::array ARR{ 9.0, 7.2, 5.4, 3.6, 1.8 };
	std::cout << "length: " << ARR.size() << '\n'; 

	// C++17, returns length as type `size_type` (alias for `std::size_t`)
	std::cout << "lenght: " << size(ARR) << '\n'; 

	// C++20, returns length as a large signed integral type
	std::cout << "length: " << std::ssize(ARR) << '\n';

	//Because the length of a std::array is constexpr, 
	// each of the above functions will return the length 
	// of a std::array as a constexpr value
	// (even when called on a non - constexpr std::array object)!

	std::array < int, 8>ARRAY{ 1,2,3,4,5,6,7,8 }; //not consexpr
	constexpr int length2{ std::size(ARRAY) }; //return value is constexpr std::size_t

	std::cout << "length2 value: " << length2 << '\n';

	std::cout << ARRAY[0] << '\n';
	std::cout << ARRAY.at(0) << '\n';

	std::cout << std::get<0>(ARRAY) << '\n';


	return 0;
} 