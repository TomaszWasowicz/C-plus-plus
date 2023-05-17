#include <iostream>
#include <cstddef> // for std::nullptr_t

void print(std::nullptr_t ptr)
{
    std::cout << "in print(std::nullptr_t)\n";
}

void print(int* ptr)
{
    std::cout << "in print(int*)\n";
}

int main()
{
    print(nullptr); // calls print(std::nullptr_t)

    int x{ 5 };
    int* ptr{ &x };

    print(ptr); // calls print(int*)

    ptr = nullptr;
    print(ptr); // calls print(int*) (since ptr has type int*)

    return 0;
}