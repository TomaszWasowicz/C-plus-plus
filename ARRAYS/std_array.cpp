#include <array>
#include <vector>
#include <iostream>

int main() {

	std::array<int, 5> a{};
	std::vector <int>b(5);

	constexpr int len{ 8 };
	std::array<int, len> b{};

	enum Colors
	{
		red,
		green,
		blue,
		max_colors
	};

	std::array<int, max_colors> c{};  //using an enum

#define DAYS_PER_WEEK 7

	std::array<int, DAYS_PER_WEEK> d{};

	std::array<int, 6> fibonacci = { 0,1,1,2,3,5 };	  //copy list initialization
	std::array<int, 5> prime{ 2,3,5,7,11 };				// list initialization using braced list

	//std::array<int, 4> toomany_initializers{ 1,2,3,4,5 }; //error
	std::array<int, 6> toolittle_initlizers{ 1,2,3 };  //lacking initializers will be initialized to 0

	const std::array<int, 4> elments_are_const_too{ 0,1,2,3 };

	const std::array<char, 8> my_letters{ 'a','b','c','d' }; //elements are constexpr

	//CLASS TEMPLATE ARGUMENT DEDUCTION
	//compiler duducts both type and the array length

	constexpr std::array what_is_it { 9.7, 7.3 }; //deducting both length and type

	//constexpr std::array <int> oh_no {1,2,3,4} //error, partial omission of just length can't be deducted
	//constexpr std::array <5> error_array{ 0,1,2,3,4 }; //error, type missing

	// since C++20, it's possible to omit the array length, by using the std::to_array helper function
	constexpr std::array moja_tablica1{ std::to_array <int, 5>({4,8,9,10,6}) };
	constexpr auto moja_tablica2{ std::to_array<int>({5,67,8,9}) };
	auto moja_talica2{ std::to_array({5,7,1,2}) };

	std::cout << moja_tablica1[3];

	return 0;
}