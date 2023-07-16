#include<iostream>
#include<iterator>
#include<array>

int main()
{
	constexpr std::array<int, 5> scores{ 84, 92, 76, 81, 56 };
	constexpr int numStudents = scores.size();

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