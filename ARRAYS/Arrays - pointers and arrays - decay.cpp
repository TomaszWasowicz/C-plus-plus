#include <iostream>

int main()
{
    int array[5]{ 9, 7, 5, 3, 1 };

    // print address of the array's first element
    std::cout << "Element 0 has address: " << &array[0] << '\n';

    // print the value of the pointer the array decays to
    std::cout << "The array decays to a pointer holding address: " << array << '\n';


    return 0;
}