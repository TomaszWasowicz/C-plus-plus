#include <iostream>

int main()
{
    int x{ 1 };
    int& ref{ x };

    std::cout << x << ref;

    int y{ 2 };
    ref = y;
    y = 3;

    std::cout << x << ref;

    x = 4;

    std::cout << x << ref;

    return 0;
}