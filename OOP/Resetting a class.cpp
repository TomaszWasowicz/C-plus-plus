#include <iostream>

class Foo
{
private:
	int m_a{ 5 };
	int m_b{ 6 };

public:
	Foo()
	{

	}

	Foo(int a, int b) :m_a{ a }, m_b{ b }
	{

	}

	void print()
	{
		std::cout << m_a << ' ' << m_b << '\n';
	}

	void reset()
	{
		*this = Foo();
	}
};

int main()
{
	Foo a{ 1,2 };

	a.print();  // obiekt Foo a{1,2};

	a.reset();

	a.print(); // obiekt Foo a{5,6}; - odwo³anie do construktora Foo(), ktory uzywa wartosci 5 i 6

	return 0;
}
