#include <iostream>

int main()
{
    int* table = new int[5] {10, 20, 30, 40, 50};
    int* originalTable = table; // Store the original address of table

    std::cout << *table++ << '\n';
    std::cout << *++table << '\n';
    std::cout << *table++ + 1 << '\n';
    std::cout << *(table - 3) << '\n';
    int i = 1;
    std::cout << i[table] << '\n';

    delete[] originalTable; // Deallocate the dynamically allocated memory

    return 0;
}
