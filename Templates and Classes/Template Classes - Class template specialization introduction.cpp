#include <iostream>

template <typename T>
class Storage8 
{
private:
	T m_array[8];

public:
	void set(int index, const T& value)
	{
		m_array[index] = value;
	}

	const T& get(int index) const
	{
		return m_array[index];
	}
};

int main()
{
	//Define s Storage8 for integers
	Storage8<int> intStorage;

	for (int count{ 0 }; count < 8; ++count)
		intStorage.set(count, count);

	for (int count{ 0 }; count < 8; ++count)
		std::cout << intStorage.get(count) << '\n';

	//Define a Storage8 for bool values
	Storage8<bool> boolStorage;
	for (int count{ 0 }; count < 8; ++count)
		boolStorage.set(count, count & 3);

	std::cout << std::boolalpha;

	for (int count{ 0 }; count < 8; ++count)
	{
		std::cout << boolStorage.get(count) << '\n';
	}

	return 0;
}