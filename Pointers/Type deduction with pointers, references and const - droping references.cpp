#include <iostream>

std::string& getRef();

int main()
{
	auto ref{ getRef() };  // brak std::string& ref ..., zamiast tego jest auto
	auto& ref2{ getRef() };  // auto ma przyczepiony znak '&' 

	return 0;
}