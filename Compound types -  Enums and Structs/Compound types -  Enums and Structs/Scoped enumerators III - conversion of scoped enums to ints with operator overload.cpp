#include <iostream>

enum class Animals
{
	chicken,
	cat,
	elephant,
	dog,
	duck,
	snake,

	maxAnimals,
};

// Overload the unary + operator to convert Animals to the underlying type
// adapted from https://stackoverflow.com/a/42198760

constexpr auto operator+(Animals a) noexcept
{
	return static_cast<std::underlying_type_t<Animals>>(a);
}

int main()
{
	std::cout << +Animals::elephant;		// convert Animals::elephant to an integer using unary operator+

	return 0;
}
