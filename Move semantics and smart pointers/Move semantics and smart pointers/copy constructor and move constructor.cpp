#include <iostream>

class String
{
public:
	String() = default;
	String(const char* string)
	{
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	String(const String& other)
	{
		printf("Copied!\n");		//implementation of the copy constructor
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other) noexcept		//implementation of the move constructor
	{
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;   //instead of allocation new block of data
									// we point to the same block of data

		other.m_Size = 0;		// we assign m_Size to be 0, we create the hollow object
		other.m_Data = nullptr;  //we assign the m_Data to the nullptr

	}

	~String()
	{
		printf("Destroyed!\n");
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
			printf("%c", m_Data[i]);

		printf("\n");
	}

private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity
{
public:
	Entity(const String& name)		//copy constructor
		:m_Name(name)
	{

	}

	Entity(String&& name)		//move constructor
		:m_Name((String&&)name)  //explicitly cast it to a temporary object
		// :m_Name(std::move(name))  - this will function too :D
	{

	}

	void PrintName()
	{
		m_Name.Print();
	}

private:
	String m_Name;
};

int main()
{
	Entity entity(String("Tomek"));
	entity.PrintName();

	std::cin.get();


	return 0;
}