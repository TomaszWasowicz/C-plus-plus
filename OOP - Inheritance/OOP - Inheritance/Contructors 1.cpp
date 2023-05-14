#include <iostream>
#include <cassert>

class U�amek
{
private:
	int m_licznik {};
	int m_mianownik {};

public:
	U�amek()   // zwyk�y konstruktor
	{
		m_licznik = 0;
		m_mianownik = 1;
	}

	U�amek(int licznik, int mianownik = 1)
	{
		assert(mianownik != 0);
		m_licznik = licznik;
		m_mianownik = mianownik;
	}

	const int& getLicznik() { return m_licznik; }
	const int& getMianownik() { return m_mianownik;  }

	void setLicznik(int licznik) { m_licznik = licznik; }
	void setMianownik(int mianownik) { m_mianownik = mianownik; }

	double getWarto��() { return static_cast<double>(m_licznik) / (m_mianownik); }
};

int main()
{
	U�amek u�amek{ 1, 10 };

	u�amek.setLicznik(20);
	u�amek.setMianownik(100);

	std::cout << u�amek.getLicznik() << '\n' << u�amek.getMianownik()<< '\n' << u�amek.getWarto��() << '\n';


	return 0;
}