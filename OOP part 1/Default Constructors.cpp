#include <iostream>

class U�amek
{
private:
	int m_licznik{};
	int m_mianownik{};

public:
	U�amek()  //default constructor - takes no parameters
	{
		m_licznik = 0;
		m_mianownik = 1;
	}

	int getLicznik() { return m_licznik; }
	int getMianownik() { return m_mianownik; }
	double getWarto��() { return static_cast<double>(m_licznik) / m_mianownik; }

};

int main()
{
	U�amek u�amek{};
	std::cout << u�amek.getLicznik() << u�amek.getMianownik() << u�amek.getWarto��() << '\n';



	return 0;
}