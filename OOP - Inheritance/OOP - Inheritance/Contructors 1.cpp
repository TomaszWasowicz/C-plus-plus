#include <iostream>
#include <cassert>

class U³amek
{
private:
	int m_licznik {};
	int m_mianownik {};

public:
	U³amek()   // zwyk³y konstruktor
	{
		m_licznik = 0;
		m_mianownik = 1;
	}

	U³amek(int licznik, int mianownik = 1)
	{
		assert(mianownik != 0);
		m_licznik = licznik;
		m_mianownik = mianownik;
	}

	const int& getLicznik() { return m_licznik; }
	const int& getMianownik() { return m_mianownik;  }

	void setLicznik(int licznik) { m_licznik = licznik; }
	void setMianownik(int mianownik) { m_mianownik = mianownik; }

	double getWartoœæ() { return static_cast<double>(m_licznik) / (m_mianownik); }
};

int main()
{
	U³amek u³amek{ 1, 10 };

	u³amek.setLicznik(20);
	u³amek.setMianownik(100);

	std::cout << u³amek.getLicznik() << '\n' << u³amek.getMianownik()<< '\n' << u³amek.getWartoœæ() << '\n';


	return 0;
}