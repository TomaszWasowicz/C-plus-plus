#include <algorithm> // for std::copy_n
#include <chrono> // for std::chrono functions
#include <iostream>

template <typename T>
class DynamicArray
{
private:
	T* m_array{};
	int m_length{};

public:
	DynamicArray(int length)
		: m_array{ new T[length] }, m_length{ length }
	{
	}

	~DynamicArray()
	{
		delete[] m_array;
	}

	// Copy constructor
	DynamicArray(const DynamicArray& arr)
		: m_length{ arr.m_length }
	{
		m_array = new T[m_length];
		std::copy_n(arr.m_array, m_length, m_array); // copy m_length elements from arr to m_array
	}

	// Copy assignment
	DynamicArray& operator=(const DynamicArray& arr)
	{
		if (&arr == this)
			return *this;

		delete[] m_array;

		m_length = arr.m_length;
		m_array = new T[m_length];

		std::copy_n(arr.m_array, m_length, m_array); // copy m_length elements from arr to m_array

		return *this;
	}

	int getLength() const { return m_length; }
	T& operator[](int index) { return m_array[index]; }
	const T& operator[](int index) const { return m_array[index]; }

};

class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using Clock = std::chrono::high_resolution_clock;
	using Second = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<Clock> m_beg{ Clock::now() };

public:
	void reset()
	{
		m_beg = Clock::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
	}
};

// Return a copy of arr with all of the values doubled
DynamicArray<int> cloneArrayAndDouble(const DynamicArray<int>& arr)
{
	DynamicArray<int> dbl(arr.getLength());
	for (int i = 0; i < arr.getLength(); ++i)
		dbl[i] = arr[i] * 2;

	return dbl;
}

int main()
{
	Timer t;

	DynamicArray<int> arr(1000000);

	for (int i = 0; i < arr.getLength(); i++)
		arr[i] = i;

	arr = cloneArrayAndDouble(arr);

	std::cout << t.elapsed();
}