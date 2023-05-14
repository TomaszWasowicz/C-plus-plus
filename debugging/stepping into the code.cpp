#include <iostream>

void printValue(int value)
{
    std::cout << value;
}

int main()
{
    printValue(5);
    printValue(6);
    printValue(7);

	int x{ 1 };
	std::cout << x << ' ';

	x = x + 2;
	std::cout << x << ' ';

	x = x + 3;
	std::cout << x << ' ';

    return 0;
}

//semantic error - program dzia³a, ale nie jak powinien
//syntax error - program nie dzia³a po naruszeniu standardu jêzyka

// F11 - step into - debug command
// wkrocz - step into - uruchamia kolejne wyra¿enia
// wykrocz - step over - uruchamia ca³e funkcje i 
						//zwraca kontrole po egzekucji
//wyjdz - step out - uruchamia CA£Y pozosta³y kod

//zaznacz kod - prawy przycisk, opcja run to cursor - uruchamia kod do miejsca zaznaczenia

// F5 - start debugging
// F5 - continue the debugging process when the debug already started and stopped 

//breakpointy - wstrzymuj¹ egzekucjê kodu do miejsca ustawienia za kazdym razem kiedy napotyka na nie debugger

// ctrl+shift+F10 - ustaw nastêpn¹ instrukcjê - omijanie instrukcji

// podczas procesu debuggowania, mozna najechaæ kursorem na instrukcjê, 
//która jest wywo³ywana, ¿eby zobaczyæ wartoœci zmiennych

// watch window - wyra¿enie kontrolne SHIFT+F9

//call stack - stos wywo³añ

//The call stack is useful in conjunction with breakpoints, 
//when your breakpoint is hit and you want to know what functions were called 
//to get to that specific point in the code.

//ALT-F11 - static analysis tool