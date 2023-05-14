#include <iostream>

int main()
{
	using distance_t = double; //zmienna distance_t jest typu double
	using miles_t = long int;
	using speed_t = long int;


	miles_t distance{ 5 };
	speed_t mhz{ 3200 };

	distance_t milesToDestination{ 3.4 }; //inicjalizacja zmiennej distance_t typu double

	std::cout << milesToDestination << '\n';

	return 0;




}