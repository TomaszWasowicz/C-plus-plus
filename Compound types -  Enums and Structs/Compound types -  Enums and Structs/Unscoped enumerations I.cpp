enum Color
{
	red,
	green,
	blue,
};

int main()
{
	Color apple{ red };
	Color shirt{ blue };
	Color cupt{ green };

	Color socks{ white };		//error no Enum like that
	Color hat{ 2 };				//error no Enum like that


	return 0;
}