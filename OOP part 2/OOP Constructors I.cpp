#include <iostream>

class U�amek
{
private:
	int licznik;
	int mianownik;

public:
	U�amek()   //default'owy konstruktor
	{
		licznik = 0;
		mianownik = 1;
	}

	int getlicznik() { return licznik; }
	int getmianownik() { return mianownik; }
	double getwarto��() { return static_cast<double>(licznik) / (mianownik); }
};

int main()
{
	U�amek u�amek{};    //call o U�amek() konstruktor
	std::cout << u�amek.getlicznik() << '/' << u�amek.getmianownik() << '\n';

	return 0;
}