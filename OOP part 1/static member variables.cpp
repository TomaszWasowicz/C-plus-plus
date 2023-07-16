#include <iostream>

class Something
{
public:
    static int m_value;
};

int Something::m_value{1};

int main()
{
    Something first;
    Something second;

    first.m_value = 2;

    std::cout << first.m_value << '\n';
    std::cout << second.m_value << '\n';

    return 0;
}