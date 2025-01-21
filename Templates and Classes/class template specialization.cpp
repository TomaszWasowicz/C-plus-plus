#include <iostream>

//first is defined a non-specialized Storage8
template<typename T>
class Storage8
{
private:
	T m_array[8];

public:
	void set(int index, const T& value) { m_array[index] = value; }
	const T& get(int index) const { return m_array[index]; }
};

//second is defined a specialized Storage8 for bool
template<>		//no template parameters
class Storage8<bool>
{

//standard class specialization details, for bool

private:
	std::uint8_t m_data{};

public:
	void set(int index, bool value)
	{
		//figure out which bit we'are setting/unsetting
		//this will put a 1 in the bit we'are interested in turning on/off
		auto mask{ 1 << index };

		if (value)  //if we'are setting a bit
			m_data |= mask;		//use the bitwise-or to turn that bit on
		else        //if we're turning a bit off
			(m_data) &= ~mask;		//bitwise-and the inverse mask to turn that bit off

	}

	bool get(int index) const
	{
		//figure out which bit we'are getting
		auto mask{1 << index};
		//bitwise-and to get the value of the bit we'are interested in
		//then implicit cast to boolean
		return (unsigned int)m_data & mask;
	}
};

int main()
{
	//define a Storage8 for integers
	Storage8<int> intStorage{};

	for (int count{ 0 }; count < 8; ++count)
		intStorage.set(count, count);

	for (int count{ 0 }; count < 8; ++count)
		std::cout << intStorage.get(count) << '\n';

	//define a  Storage8 for bool
	Storage8<bool> boolStorage{};

	for (int count{ 0 }; count < 8; ++count)
		boolStorage.set(count, count & 3);

	std::cout << std::boolalpha;

	for (int count{ 0 }; count < 8; ++count)
	{
		std::cout << boolStorage.get(count) << '\n';
	}

	return 0;
}