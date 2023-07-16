#include <iostream>

int main()
{
    char myString[]{ "string" };
    myString[1] = 'p';
    std::cout << myString << myString[0]<< '\n'; // s(p)ring(s)

    return 0;
}