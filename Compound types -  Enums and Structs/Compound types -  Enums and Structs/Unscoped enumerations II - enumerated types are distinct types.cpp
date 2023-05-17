enum Pet
{
	cat,
	dog,
	whale,
	bird,
	pig,
};

enum Color
{
	yellow,
	blue,
	white,
	red,
};

int main()
{
	Pet mypet{ yellow };	//error: no enum in Pet like yellow
	Color shirt{ pig };		//error: no enum in Color like pig

	return 0;
}