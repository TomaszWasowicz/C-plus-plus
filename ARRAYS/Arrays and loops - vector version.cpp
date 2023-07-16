#include<iostream>
#include<iterator>
#include <vector>

int main()
{
	std::vector<int> scores{ 84,92,76,81,56 }; //remove constexpr, vectors are not compile time
	int numStudents = scores.size(); // same as above

	int maxScore{ 0 };
	for (int student{ 0 }; student < numStudents; ++student)
	{
		if (scores[student > maxScore])
		{
			maxScore = scores[student];
		}
	}

	std::cout << "The best score was: " << maxScore << '\n';


	return 0;
}