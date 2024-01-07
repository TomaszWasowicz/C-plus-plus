//referencja dzia³a tylko na zainicjalizowanej zmiennej
//i tylko na zmiennej, ktora moze byc zmodyfikowana
//referencja nie moze byc zmieniona zjednej zmiennej na inna zmienna
// referencje i zmienne maj¹ odmienny czas zycia
// niszcz¹c obiekt, do ktorego nawiazuej referencja
//i zostawiajac referencje, mozna doprowadzic do nieznanego zachowania

#include <iostream>

int main()
{
	int x{ 5 };
	int& ref{ x };

	int y{ 4 };

	{	
		int& ref2{ y };
	}

	//std::cout << ref2 << '\n'; - zycie referencje zakoczylo sie powyzej

	std::cout << x << '\n';
	std::cout << ref << '\n';

	ref = 7;		//modyfikacja zmiennej x

	std::cout << x << ref << '\n'; // i x i referencja maja teraz wartosc 7

	return 0;
} 