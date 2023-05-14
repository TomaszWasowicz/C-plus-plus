#include <iostream>

int main()
{
	for (int count{ 0 }; count < 10; ++count)
	{
		if ((count % 4) == 0)					// jeœli count jest podzielne przez 4
			continue;							//kontynuuj iteracjê

		if ((count < 8))
			continue;

												// jeœli count NIE jest podzielne przez 4
		std::cout << count << '\n';				//wyœwietl count		
												// ... i kontynuuj iteracjê

	}

	return 0;
}

//1 2 3 5 6 7 8 9  - bez 4