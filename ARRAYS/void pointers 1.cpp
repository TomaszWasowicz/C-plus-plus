#include <iostream>
#include <cassert>

enum class Type
{
	type_Int,
	type_Float,
	type_CString
};

void printValue(void* ptr, Type type)
{
	switch (type)
	{
	case Type::type_Int:
		std::cout << *static_cast<int*>(ptr) << '\n';
		break;
	case Type::type_Float:
		std::cout << *static_cast<float*>(ptr) << '\n';
		break;
	case Type::type_CString:
		std::cout << static_cast<char*>(ptr) << '\n';
		break;
	default:
		assert(false && "type not found");
		break;
	}
}

int main()
{
	int nValue{ 5 };
	float fValue{ 7.5f };
	char szValue[]{ "Mollie" };

	printValue(&nValue, Type::type_Int);
	printValue(&fValue, Type::type_Float);
	printValue(&szValue, Type::type_CString);



	return 0;
}