#include <iostream>

int main()
{
	for (int count{ 0 }; count < 10; ++count)
	{
		if ((count % 4) == 0)					// je�li count jest podzielne przez 4
			continue;							//kontynuuj iteracj�

		if ((count < 8))
			continue;

												// je�li count NIE jest podzielne przez 4
		std::cout << count << '\n';				//wy�wietl count		
												// ... i kontynuuj iteracj�

	}

	return 0;
}

//1 2 3 5 6 7 8 9  - bez 4