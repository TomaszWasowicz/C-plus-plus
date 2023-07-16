#include <iostream>
#include <iterator>
#include<vector>

int main()
{
	std::vector<int> scores{ 84,92,76,81,56 };

	for (int i{ 0 }; i < scores.size(); ++i)
	{
		std::cout << scores[i] << '\n';
	}

	int numStudents = scores.size() ;

	int maxScore{ 0 };
	for (int student{ 0 }; student <= numStudents; ++student) 
		//error - looping 0 - 5, when an array is indexed 0 - 4
		//can be corrected if '=' is removed
	{
		if (scores[student] > maxScore)
		{
			maxScore = scores[student];
		}
	}

	std::cout << "The best score was: " << maxScore << '\n';

	return 0;
}