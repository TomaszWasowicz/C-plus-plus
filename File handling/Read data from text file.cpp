#include <iostream>
#include <fstream>
//#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <string>

int main(int argc, char* argv[])
{
	std::string line{};
	int i{};
	if (argc != 2)
	{
		std::cout << "Usage: myReaddFile <fileName>" << std::endl;
		return 1;
	}
	std::ifstream mFile(argv[1]);
	if (mFile.is_open())
	{
		i = 0;
		while (getline(mFile, line))
		{
			i++;
			if (i == 1 || i == 20000)
				std::cout << line << std::endl;
		}
		mFile.close();
	}


	return 0;
}