#include <iostream>

class A
{
public:
    A() { std::cout << "A\n"; }
};

class B
{
private:
    A m_a;  // najpierw wywoluje A z public A()

public:
    B() { std::cout << "B\n"; } // potem wywo³uje B z public B()
};

int main()
{
    B b;        //  A B|
    return 0;
}