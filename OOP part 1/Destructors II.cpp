#include <iostream>

class Simple
{
private:
	int m_nID{};

public:
	Simple(int nID): m_nID{nID}
	{
		std::cout << "Contructing Simple " << nID << '\n';
	}

	~Simple()
	{
		std::cout << "Destructing Simple" << m_nID << '\n';
	}

	int getID() { return m_nID; }
};

int main()
{
	//Allocate a Simple on stack
	Simple simple{ 1 };
	std::cout << simple.getID() << '\n';

	//Allocate a Simple dynamically
	Simple* pSimple{ new Simple{2} };

	std::cout << pSimple->getID() << '\n';

	//We allocated pSimple dynamically, so we have to delete it.
	delete pSimple;

	return 0;
} //simple goes out of scope here

