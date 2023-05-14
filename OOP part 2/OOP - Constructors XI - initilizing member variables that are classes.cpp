#include <iostream>

class A
{
public:
	A(int x = 0) { std::cout << "A" << x << '\n'; }
};

class B
{
private:
	A m_a{};
public:
	B(int y) : m_a{ y - 1 } { std::cout << "B" << y << '\n'; }  //
};

int main()
{
	B b{ 5 };

	return 0;
}