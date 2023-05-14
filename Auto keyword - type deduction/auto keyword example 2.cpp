#include <iostream>

auto addAndPrint(auto x, auto y) // funckja typu void
{
    std::cout << x + y;
}

int main()
{
    addAndPrint(2, 3); // case 1: call addAndPrint with int parameters
    addAndPrint(4.5, 6.7); // case 2: call addAndPrint with double parameters
}