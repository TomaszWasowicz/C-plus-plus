#include <iostream>

/*
A pointer is an object that holds a memory address 
(typically of another variable) as its value. 
This allows us to store the address of some other object to use later.
*/


int main()
{
    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x


    //operator dereferencji - wydrukuje wartosc spod adresu pamieci
    std::cout << *(&x) << '\n'; // print the value at the memory address of variable x (parentheses not required, but make it easier to read)

    return 0;
}