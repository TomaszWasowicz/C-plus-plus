#include <iostream>

int value{ 5 }; //zmienna globalna

int main()
{
	int value{ 7 };  // chowanie zmiennej globalnej
	++value;    //inkrementacja zmiennej lokalnej
	--::value;  //dekrementacja zmiennej globalnej, nie lokalnej ( nawias niepotrzebny)

	// uzycie operatora scope'u mowi kompilatorowi, ze chcemy dostepu do zmiennej globalnej

	std::cout << "zmienna lokalna to: " << value << '\n';
	std::cout << "zmienna globalna to " << ::value << '\n';

	// zmienne globalne pozna oznaczac prefiksem "g_"

	return 0;
}
