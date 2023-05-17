#include <iostream>

int main()
{

    const int x{ 5 };
    const int y{ 8 };

    const int* ptr{ &x }; // ptr points to const int x

    std::cout << *ptr << '\n';

    ptr = &y; // okay: ptr now points at const int y

    std::cout << *ptr << '\n';

    return 0;
}