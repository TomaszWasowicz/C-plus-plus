#include <iostream>

class Foo
{
private:
    int m_value{ 4 };

public:
    int& getValue() { return m_value; } // returns a non-const reference
};

int main()
{
    Foo f;                     // f.m_value is initialized to 4
    f.getValue() = 5;          // use the non-const reference to assign value 5 to m_value
    std::cout << f.getValue(); // prints 5

    return 0;
}