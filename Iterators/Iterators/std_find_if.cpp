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
	
    // Iterate through the vector and check each element for the substring 'nut'
    for (const auto& str : std::vector<std::string_view>{ "apple", "pear", "banana", "coconut", "walnut", "lemon" })
    {
        if (containsNut(str))
        {
            std::cout << "Found " << str << '\n';
        }
    }

	return 0;
}