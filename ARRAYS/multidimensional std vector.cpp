#include <iostream>
#include <vector>


int main()
{

	constexpr int numRows{ 10 };
	constexpr int numColumns{ 10 };

	std::vector<std::vector<int>> multi_array(numRows, std::vector<int>(numColumns));

	for (int row{ 1 }; row < numRows; ++row)
	{
		for (int col{ 1 }; col < numColumns; ++col)
		{
			multi_array[row][col] = row * col;
		}
	}

	for (int row{ 1 }; row < numRows; ++row)
	{
		for (int col{ 1 }; col < numColumns; ++col)
		{
			std::cout << multi_array[row][col] << '\t';
		}

		std::cout << '\n';
	}




	return 0;
}