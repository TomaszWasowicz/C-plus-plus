#include <iostream>

class Simple
{
private:
	int m_id{};

public:
	Simple(int id): m_id{id}{}

	int getID() const { return m_id; }
	void setID(int id) { this->m_id = id; }

	void print() const { std::cout << this->m_id; }

	//void print() const { std::cout << (*this).m_id; }	// 2nd way

	//void print() const { std::cout << this->getID(); }	//3rd way

	// use 'this' pointer to access the implicit object and operator-> to select member m_id
};

int main() {

	Simple simple{ 1 };
	simple.setID(2);

	simple.print();

	return 0;
}