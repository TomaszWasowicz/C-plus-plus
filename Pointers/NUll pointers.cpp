#include<iostream>

void someFunction()
{
    std::cout << "boop" << '\n';
}



int main()
{
    int* ptr{ nullptr }; // can use nullptr to initialize a pointer to be a null pointer

    int value{ 5 };
    int* ptr2{ &value }; // ptr2 is a valid pointer
    ptr2 = nullptr; // Can assign nullptr to make the pointer a null pointer

    someFunction(nullptr); // we can also pass nullptr to a function that has a pointer parameter

    return 0;
}