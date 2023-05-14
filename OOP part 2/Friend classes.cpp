#include <iostream>

class Storage
{
private:
	int m_nValue{};
	double m_dValue{};

public:
	Storage(int nValue, double dValue):
		m_nValue{ nValue }, m_dValue{ dValue }
	{

	}
	friend class Display;
};

class Display
{
private:
	bool m_displayIntFirst;

public:
	Display(bool displayIntFirst)
		: m_displayIntFirst{ displayIntFirst }
	{

	}

	void displayItem(const Storage& storage)
	{
		if (m_displayIntFirst)
			std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
		else
			std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
	}
};

int main()
{
	Storage storage{ 5, 6.7 };
	Display display{ false };

	display.displayItem(storage);

	return 0;
}