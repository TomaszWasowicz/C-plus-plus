#include <iostream>

class Something
{
private:
	int m_value{};

public:
	Something() : m_value{ 0 }{}

	void resetValue() { m_value = 0; }   // compile error, const functions can't change member variables

	void setValue(int value) { m_value = value; }
	int getvalue() const; //function prototype and the function definition below must have const
};

int Something::getvalue() const // must have const like the prototype
{
	return m_value;
}

int main()
{
	const Something something{};

	//something.m_value = 5;  //compiler error: violates const
	//something.setValue(0);	//compiler error: violates const
	something.getvalue();
}