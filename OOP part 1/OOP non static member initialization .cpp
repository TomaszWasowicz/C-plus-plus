#include <iostream>

class Prostokat
{
private:
	double m_dlugosc{ 1.0 };
	double m_szerokosc{ 1.0 };

public:

	Prostokat(double szerokosc, double dlugosc)
		: m_dlugosc{ dlugosc },
		m_szerokosc{ szerokosc }
	{

	}

	Prostokat(double dlugosc) : m_dlugosc{ dlugosc }
	{
		//m_dluosc jest zainicjalizowana przez konstruktor
		//m_szerokosc defaultowa wartosc (1.0) jest u¿yta
	}

	void print()
	{
		std::cout << "dlugosc : " << m_dlugosc << ", szerokosc: " << m_szerokosc << '\n';
	}
};

int main()
{
	Prostokat x{2.0,3.0};
	x.print();

	Prostokat y{ 4.0 };
	y.print();




	return 0;
}