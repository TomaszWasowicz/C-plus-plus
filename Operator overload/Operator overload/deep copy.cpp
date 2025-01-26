#include <cstring> // for strlen()
#include <cassert> // for assert()
#include <iostream>

class MyString
{
private:
    char* m_data{};
    int m_length{};

public:
    explicit MyString(const char* source = "")
    {
        assert(source); // make sure source isn't a null string

        // Find the length of the string
        // Plus one character for a terminator
        m_length = std::strlen(source) + 1;

        // Allocate a buffer equal to this length
        m_data = new char[m_length];

        // Copy the parameter string into our internal buffer
        for (int i{ 0 }; i < m_length; ++i)
            m_data[i] = source[i];
    }

    //Copy constructor for deep copy
	MyString(const MyString& source)
	{
		// Make sure we have our own buffer
		if (source.m_data)
		{
			// First do what the default constructor does
			m_length = source.m_length;
			m_data = new char[m_length];
			// Then copy the source string into our internal buffer
			for (int i{ 0 }; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
		{
			m_data = nullptr;
			m_length = 0;
		}
	}

    ~MyString() // destructor
    {
        // We need to deallocate our string
        delete[] m_data;
    }

    char* getString() { return m_data; }
    int getLength() const { return m_length; }
};

int main()
{
    MyString hello{ "Hello, world!" };
    {
        MyString copy{ hello }; // use copy constructor for deep copy
    } // copy is a local variable, so it gets destroyed here.

    std::cout << hello.getString() << '\n'; // this will work fine

    return 0;
}

