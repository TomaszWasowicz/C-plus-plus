#include <iostream>

template<typename T>
class Auto_ptr5
{
	T* m_ptr{};
public:
	Auto_ptr5(T* ptr = nullptr)
		: m_ptr{ ptr }
	{
	}

	~Auto_ptr5()
	{
		delete m_ptr;
	}

	// Copy constructor -- no copying allowed!
	Auto_ptr5(const Auto_ptr5& a) = delete;

	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr5(Auto_ptr5&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
	}

	// Copy assignment -- no copying allowed!
	Auto_ptr5& operator=(const Auto_ptr5& a) = delete;

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr5& operator=(Auto_ptr5&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr5<Resource> generateResource()
{
	Auto_ptr5<Resource> res{ new Resource };
	return res; // this return value will invoke the move constructor
}

int main()
{
	Auto_ptr5<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the move assignment

	return 0;
}