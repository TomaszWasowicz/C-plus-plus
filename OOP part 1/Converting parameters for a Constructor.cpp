#include <iostream>
class Foo
{
private:
	int m_x{};
public:
	Foo(int x) : m_x{x}{}   //only because this constructor is present I can convert int to Foo

	int getX() const 
	{ 
		return m_x; 
	}
};

void printFoo(Foo f) //has a Foo parameter
{
	std::cout << f.getX();
}

int main()
{
	printFoo(5);   
	
	//we are supplying an int param,
	// but printFoo() has a Foo parameter
	//Because the types don't match, 
	// the compilaer will try to implicitly convert int value 5 into Foo object
	//so the function can be called


	return 0;
}