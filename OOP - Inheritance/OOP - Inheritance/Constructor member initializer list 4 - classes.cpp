#include <iostream>

class A
{
public:
	explicit A(int x = 0) { std::cout << "A " << x << '\n'; }
};

class B
{
private:
	A m_a{};

public:
	explicit B(int y) : m_a{ y - 1 }
	{
		std::cout << "B " << y << '\n';
	}
};

int main()
{
	B b{ 5 }; // A 4 B 5

	return 0;
}