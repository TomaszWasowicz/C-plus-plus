class Accumulator
{
private:
	int m_value{ 0 };

public:
	void add(int value)
	{
		m_value += value;
	}

	friend void reset(Accumulator& accumulator); //friend reset function
};

void reset(Accumulator& accumulator) //reset function is a friend of Accumulator class
{
	accumulator.m_value = 0; // and can access the private data of Accumulator class objects
}

int main()
{
	Accumulator acc;
	acc.add(5);
	reset(acc);

	return 0;
}