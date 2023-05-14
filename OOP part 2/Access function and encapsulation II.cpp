#include <iostream>

class Something
{
private:
	int m_value[3];
public:
	void setValue1(int value) { m_value[0] = value; }
	int getValue1() { return m_value[0]; }
};

int main()
{
	Something something;
	something.setValue1(5);
	std::cout << something.getValue1() << '\n';

	//std::cout << something.setValue1(10) << '\n';


	return 0;
}
