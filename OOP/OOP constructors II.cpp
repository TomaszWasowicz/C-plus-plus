#include <iostream>

class Data 
{
private:
	int m_rok{ 1900 };
	int m_miesi¹c{ 12 };
	int m_dzieñ{ 15 };

public:
	Data(int rok, int miesi¹c, int dzieñ)
	{
		m_rok = rok;
		m_miesi¹c = miesi¹c;
		m_dzieñ = dzieñ;
	}

	Data() = default;
};

int main()
{
	Data data{}; // odwo³uje siê do Data() = default;

	Data dziœ{ 2022, 06, 16 };



	return 0;
}