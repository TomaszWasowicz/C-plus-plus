#include<iostream>
#include<string>
#include<vector>
#include<chrono>


class myData
{
private:
	std::string* pData;
public:

	//constructor

	myData(const std::string& inStr)
	{
		pData = new std::string(inStr);
		//std::cout << "Class myData constructor 1: create " << pData << " " << *pData << std::endl;
	}

	//copy constructor

	myData(myData& inObj)
	{
		pData = new std::string(*inObj.pData);
		//std::cout << "Class myData constructor 2: copy " << pData << " " << *pData << std::endl;
	}

	//move constructor

	myData(myData&& inObj)
	{
		pData = inObj.pData;
		inObj.pData = nullptr;
		//std::cout << "Class myData constructor 3: move " << pData << " " << *pData << std::endl;
	}

	~myData() {
		delete pData;
	}
};

int main()
{
	std::vector<myData> mVec;


	//timing for std::move

	typedef std::chrono::high_resolution_clock Clock;
	typedef std::chrono::milliseconds milliseconds;

	Clock::time_point tStart = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 10000; i++) {
		mVec.push_back(myData("Hello World I am saving to the vector"));
	}

	Clock::time_point tEnd = std::chrono::high_resolution_clock::now();
	std::chrono::milliseconds execTime = std::chrono::duration_cast<milliseconds>(tEnd - tStart);
	std::cout << "With Move Running time " << execTime.count() << " ms" << std::endl;

	//myData myObj = myData("Hello World I am here");
	//myData cpObj = myObj;

	return 0;
}