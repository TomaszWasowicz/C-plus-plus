#include <iostream>
#include <cassert>

class U�amek
{
private:
	int m_licznik{};
	int m_mianownik{};

public:
	
	U�amek(int licznik = 0, int mianownik=1) // konstruktor z 2 parametrami, jeden ma default value
	{
		assert(mianownik != 0);  // assert mianownik rozny od 0

		m_licznik = licznik;
		m_mianownik = mianownik;
	}

	int getLicznik() { return m_licznik; }
	int getMianownik() { return m_mianownik; }
	double getValue() { return static_cast<double>(m_licznik) / m_mianownik; }
};

int main()
{
	U�amek zero{};  // odwo�anie do podstawowego konstruktora
	std::cout << zero.getLicznik() << '/' << zero.getMianownik() << '\n';

	U�amek sze��{ 6 };  // odwo�anie do podstawowego konstruktora, ale licznik na 6
	std::cout << sze��.getLicznik() << '/' << sze��.getMianownik() << '\n';

	U�amek pi��_trzecich{ 5, 3 }; // odwo�anie do podstawowego konstruktora, licznik na 5, mianownik na 3
	std::cout << pi��_trzecich.getLicznik() << '/' << pi��_trzecich.getMianownik() << '\n';
	

	return 0;
}
