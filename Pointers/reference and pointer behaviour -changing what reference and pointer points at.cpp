#include <iostream>

int main()
{
	int x{ 5 };
	int& ref{ x };
	int* ptr{ &x }; // pointer zainicjalizaowany adresem zmiennej x

    std::cout << x << '\n';
    std::cout << ref << '\n'; // use the reference to print x's value (5)
    std::cout << ptr << '\n'; //adress of the ptr
    std::cout << *ptr << '\n'; // use the pointer to print x's value (5)

    ref = 6; // use the reference to change the value of x
    std::cout << x << '\n';
    std::cout << ref << '\n';  // use the reference to print x's value (6)
    std::cout << ptr << '\n';  // SAME adress of the ptr
    std::cout << *ptr << '\n'; // use the pointer to print x's value (6)

    *ptr = 7; // use the pointer to change the value of x
    std::cout << x << '\n';
    std::cout << ref << '\n';  // use the reference to print x's value (7)
    std::cout << ptr << '\n';  // SAME adress of the ptr
    std::cout << *ptr << '\n'; // use the pointer to print x's value (7)


	return 0;

}