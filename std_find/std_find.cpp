#include <algorithm>
#include <vector>
#include <iostream>
#include <memory>

int main()
{
	std::vector v = { 1,2,3,4 };

	v.push_back(12);
	v.push_back(5);

	for (int n : {3, 5})
		(std::ranges::find(v.begin(), v.end(), n) == v.end())
		? std::cout << "v does not contain " << n << '\n'
		: std::cout << "v contains " << n << '\n';

	auto is_even = [](int i) { return i % 2 == 0; };

	for (std::vector<std::vector<int>> v2 = { std::vector<int>{3,1,4}, std::vector<int>{1,3,5} }; const auto& w : v2)
	{
		auto it = std::ranges::find_if(w.begin(), w.end(), is_even);
		if (it != w.end())
			std::cout << "w contains an even number " << *it << '\n';
		else
			std::cout << "w does not contain even numbers\n";
	}

	return 0;
}
