#include <iostream>

int main()
{
	int i1 = 3.5; // the 0.5 is dropped, resulting in lost data
	int i2 = 3.0; // okay, will be converted to value 3, so no data is lost

	return 0;
}