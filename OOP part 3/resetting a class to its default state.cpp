#include <iostream>

class Calc
{
private:
	int m_value{};

public:
	Calc& add(int value) { m_value += value; return *this; }
	Calc& substract(int value) { m_value -= value; return *this; }
	Calc& multiply(int value) { m_value *= value; return *this; }

	int getValue() const{return m_value;}

	void reset() { *this = {}; }
};

int main()
{
	Calc calc{};
	calc.add(5).substract(3).multiply(2);

	std::cout << calc.getValue() << '\n';

	calc.reset();

	std::cout << calc.getValue() << '\n';

	return 0;
}