#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    std::cout << "Enter a value to search for and replace with: ";
    int search{};
    int replace{};
    std::cin >> search >> replace;

    // Input validation omitted

    // std::find returns an iterator pointing to the found element (or the end of the container)
    // we'll store it in a variable, using type inference to deduce the type of
    // the iterator (since we don't care)
    auto found{ std::find(arr.begin(), arr.end(), search) };

    // Algorithms that don't find what they were looking for return the end iterator.
    // We can access it by using the end() member function.
    if (found == arr.end())
    {
        std::cout << "Could not find " << search << '\n';
    }
    else
    {
        // Override the found element.
        *found = replace;
    }

    for (int i : arr)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}