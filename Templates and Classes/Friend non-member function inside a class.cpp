#include <iostream>

class Accumulator
{
private:
	int m_value{0};
public:
	void add(int value) { m_value += value; }

	//Friend function defined inside a class are non-member fucntions
	friend void print(const Accumulator& accumulator)
	{
		//Because print() is a friend of Accumulator
		//it can access the private members of Accumulator
		std::cout << accumulator.m_value << '\n';
	}
};

int main()
{
	Accumulator acc{};
	acc.add(5); //add 5 to the accumulator
	print(acc);	//call the print() non-member function

	return 0;
}