#include <iostream>

class U³amek
{
private:
	int licznik;
	int mianownik;

public:
	U³amek()   //default'owy konstruktor
	{
		licznik = 0;
		mianownik = 1;
	}

	int getlicznik() { return licznik; }
	int getmianownik() { return mianownik; }
	double getwartoœæ() { return static_cast<double>(licznik) / (mianownik); }
};

int main()
{
	U³amek u³amek{};    //call o U³amek() konstruktor
	std::cout << u³amek.getlicznik() << '/' << u³amek.getmianownik() << '\n';

	return 0;
}