#include <iostream>

class Calc
{
private:
	int m_value{};
public:
	Calc& add(int value) { m_value += value; return *this; }
	Calc& substract(int value) { m_value -= value; return *this; }
	Calc& multiply(int value) { m_value *= value; return *this; }

	int getValue() const { return m_value; }
};

int main()
{
	Calc calc{};
	calc.add(5).substract(2).multiply(3);
	// Because this always points to the implicit object, 
	// we don’t need to check whether it is a null pointer before dereferencing it.

	std::cout << calc.getValue() << '\n';

	return 0;
}


/*
* standard way
* 
class Calc
{
private:
	int m_value{};
public:
	void add(int value) { m_value += value; }
	void substract(int value) { m_value -= value; }
	void multiply(int value) { m_value *= value; }

	int getValue() const { return m_value; }
};

int main()
{
	Calc calc;
	calc.add(5);
	calc.substract(2);
	calc.multiply(3);

	std::cout << calc.getValue() << '\n';


	return 0;
}

*/