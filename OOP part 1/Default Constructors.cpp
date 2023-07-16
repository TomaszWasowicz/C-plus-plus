#include <iostream>

class U³amek
{
private:
	int m_licznik{};
	int m_mianownik{};

public:
	U³amek()  //default constructor - takes no parameters
	{
		m_licznik = 0;
		m_mianownik = 1;
	}

	int getLicznik() { return m_licznik; }
	int getMianownik() { return m_mianownik; }
	double getWartoœæ() { return static_cast<double>(m_licznik) / m_mianownik; }

};

int main()
{
	U³amek u³amek{};
	std::cout << u³amek.getLicznik() << u³amek.getMianownik() << u³amek.getWartoœæ() << '\n';



	return 0;
}