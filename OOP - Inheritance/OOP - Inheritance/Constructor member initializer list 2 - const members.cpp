#include<iostream>

class Something
{
private:
	const int m_value;

public:
	Something(int x) : m_value{ x }  // stale trzeba inicjalizowac
	{
	}

	void print()
	{
		std::cout << "Something " << m_value << '\n';
	}

};

int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	Something s{ x };
	s.print();

	return 0;
}