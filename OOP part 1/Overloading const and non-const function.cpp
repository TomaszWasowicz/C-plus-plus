#include <string>

class Something
{
private:
	std::string m_value{};

public:
	Something(const std::string& value=""): m_value{value}{}

	const std::string& getVaue() const { return m_value; }
	std::string& getValue() { return m_value; }
};

int main()
{
	Something something;
	something.getValue() = "Hi";	//wo³a non-const getValue();

	const Something something2;
	something2.getVaue();      //wo³a const getValue();


	return 0;
}