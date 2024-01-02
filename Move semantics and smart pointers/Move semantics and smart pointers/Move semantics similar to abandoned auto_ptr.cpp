#include <iostream>

template<typename T>
class Auto_ptr2
{
	T* m_ptr;
public:
	Auto_ptr2(T* ptr=nullptr): m_ptr(ptr){}

	~Auto_ptr2()
	{
		delete m_ptr;
	}

	Auto_ptr2(Auto_ptr2& a)		// copy contructor implementing move semantics
	{
		m_ptr = a.m_ptr;		// transfer our dumb pointer from the source to our local object
		a.m_ptr = nullptr;		// make sure the source no longer owns the pointer
	}

	Auto_ptr2& operator=(Auto_ptr2 a)		// An assignment operator that implements move semantics
	{
		if (&a == this)
			return *this;

		delete m_ptr;		// make sure we deallocate any pointer the destination is already holding first
		m_ptr = a.m_ptr;	// then transfer our dumb pointer from the source to the local object
		a.m_ptr = nullptr;	// make sure the source no longer owns the pointer
		return *this;
	}

	T& operator*() const { 
		return *m_ptr; 
	}
	T* operator->() const { 
		return m_ptr; 
	}
	bool isNull() const {
		return m_ptr == nullptr;
	}
};

class Resource
{
public:
	Resource() {
		std::cout << "Resource acquired\n";
	}
	~Resource() {
		std::cout << "Resource destroyed\n";	// Throwing an exception from a destructor may result in a call to std::terminate.
												//If std::terminate is called, the program terminates in an implementation-defined, abrupt, and unclean manner.
											
	}
};

int main()
{
	Auto_ptr2<Resource> res1(new Resource());
	Auto_ptr2<Resource> res2;    // zaczyna jako null_ptr

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	res2 = res1;		// res2 przejmuje ownership, res1 jest ustawiane na null

	std::cout << "Ownership transfered\n";

	std::cout << "res1 is : " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is : " << (res2.isNull() ? "null\n" : "not null\n");


	return 0;
}