#include <iostream>

class Something
{
private:
	int m_value1{};
	double m_value2{};
	char m_value3{};
	const int m_value4{};

public:
	Something(int value1, double value2, char value3, const int value4)
		:m_value1{ value1 }, m_value2{ value2 }, m_value3{value3}, m_value4{value4}
	{

	}

	void print() const
	{
		std::cout << "Something: " 
			<< m_value1 << ' ' << m_value2 << ' ' << m_value3 << ' ' << m_value4 << '\n';
	}
};

int main()
{
	Something something{1,2.2,'c',10};
	something.print();

	return 0;
}