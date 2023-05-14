#include <iostream>

auto foo();    //funkcja auto musi byc w pelni zdefiniowana by byc uzyta

int main()
{
    std::cout << foo(); // the compiler has only seen a forward declaration at this point
    return 0;
}

auto foo()
{
    return 5;
}