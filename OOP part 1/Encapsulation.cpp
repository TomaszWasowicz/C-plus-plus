#include <iostream>

class Something
{
private:
	int m_value1[3];

public:
	void setValue(int value){m_value1[0] = value; }
	int getValue1() const{return m_value1[0];}
};

int main()
{
	Something something;
	something.setValue(15);
	std::cout << something.getValue1() << '\n';


	return 0;
}