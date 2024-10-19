#include <iostream>
#include <fstream>
#include <p_thread.h>
#include <stdio.h>
#include <string.h>
#include <string>

#define MAX_THREADS 2

struct threadParam
{
	int t_id{};
	char t_FileName[30];
};

void* ReadFile(void* tParam)
{
	struct threadParam* mData;
	mData = (struct threadParam*)tParam;
	std::string line{};
	int i{}, initPos{};
	initPos = mData->t_id * 10000 * 27;

	std::ifstream myFile(mData->t_FileName);
	if (myFile.is_open())
	{
		i = 0;
		myFile.seekg(initPos, std::ios::beg);
		while (getline(myFile, line) && i < 10000)
		{
			i++;
			if (i == 1 || i == 10000)
				std::cout << "Thread " << mData->t_id << " : " << line << std::endl;
		}
		myFile.close();
	}
	else {
		std::cout << "can not open file example.txt for reading" << std::endl;
	}

	phread_exit(NULL);
}

int main(int argc, char* argv[])
{

	pthread_t threads[MAX_THREADS];
	struct threadParam mTD[MAX_THREADS];
	int j, rc;

	if (argc != 2)
	{
		std::cout << "Usage: myReaddFile <fileName>" << std::endl;
		return 1;
	}

	for (j = 0; j < MAX_THREADS; j++)
	{
		mTD[j].t_id = j;
		memset(mTD[j].t_FileName, '\0', sizeof(mTD[j].t_FileName));
		memcpy(mTD[j].t_FileName, argv[1], strlen(argv[1]));
		rc = pthread_create(&threads[j], NULL, ReadFile, (void*)&mTD[j]);
		if (rc) {
			std::cout << "Error:unable to create thread," << rc << std::endl;
			exit(-1);
		}
	}

	p_thread_exit(NULL);

	return 0;
}