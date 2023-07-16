#include <iostream>
#include <vector>

void bubbleSort( std::vector<long long>& v)
{
	size_t n = v.size();

	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = 0; j < n - i - 1;j++)
		{
			if (v[j] > v[j + 1])
			{
				long long temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

int main()
{
	std::vector<long long> v = { 64,34,25,12,22,11,90 };

	std::cout << "Original vector: " << '\n';
	for (auto num : v)
	{
		std::cout << num << " ";
	}

	bubbleSort(v);

	std::cout << "\nSorted vector: " << '\n';
	for ( auto num : v)
	{
		std::cout << num << " ";
	}


	return 0;
}