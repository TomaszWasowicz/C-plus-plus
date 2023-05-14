#include <iostream>
#include <cassert>

class U³amek
{
private:
	int m_licznik{};
	int m_mianownik{};

public:
	
	U³amek(int licznik = 0, int mianownik=1) // konstruktor z 2 parametrami, jeden ma default value
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
	U³amek zero{};  // odwo³anie do podstawowego konstruktora
	std::cout << zero.getLicznik() << '/' << zero.getMianownik() << '\n';

	U³amek szeœæ{ 6 };  // odwo³anie do podstawowego konstruktora, ale licznik na 6
	std::cout << szeœæ.getLicznik() << '/' << szeœæ.getMianownik() << '\n';

	U³amek piêæ_trzecich{ 5, 3 }; // odwo³anie do podstawowego konstruktora, licznik na 5, mianownik na 3
	std::cout << piêæ_trzecich.getLicznik() << '/' << piêæ_trzecich.getMianownik() << '\n';
	

	return 0;
}
