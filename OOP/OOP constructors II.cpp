#include <iostream>

class Data 
{
private:
	int m_rok{ 1900 };
	int m_miesi�c{ 12 };
	int m_dzie�{ 15 };

public:
	Data(int rok, int miesi�c, int dzie�)
	{
		m_rok = rok;
		m_miesi�c = miesi�c;
		m_dzie� = dzie�;
	}

	Data() = default;
};

int main()
{
	Data data{}; // odwo�uje si� do Data() = default;

	Data dzi�{ 2022, 06, 16 };



	return 0;
}