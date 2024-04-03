#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <vector>

static bool containsNut(std::string_view str)
{
	return (str.find("nut") != std::string_view::npos);
}

int main()
{
	std::vector<std::string_view> v{ "apple", "banana", "walnut", "lemon", "coconut", "peanut" };

	auto nuts{ std::ranges::count_if(v,containsNut) };

	std::cout << "Counted " << nuts << " nut(s)\n";

	return 0;
}