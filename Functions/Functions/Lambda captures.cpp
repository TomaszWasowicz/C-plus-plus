#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>

int main()
{
    std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    std::cout << "search for: ";

    std::string search{};
    std::cin >> search;

    // Capture @search                                vvvvvv
    auto found{ std::find_if(arr.begin(), arr.end(), [search](std::string_view str) {
      return (str.find(search) != std::string_view::npos);
    }) };

    if (found == arr.end())
    {
        std::cout << "Not found\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    return 0;
}