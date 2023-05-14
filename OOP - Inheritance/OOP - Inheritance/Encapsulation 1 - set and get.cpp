#include <iostream>

class Something
{
private:
	int m_value1{};
	int m_value2{};
	int m_value3{};

public:
	void setValue1(int value) 
	{ 
		m_value1 = value; 
	}
	int getValue1() 
	{ 
		return m_value1; 
	}
};

int main()
{
	Something s1;
	s1.setValue1(5);

	std::cout << s1.getValue1() << '\n';

	return 0;
}