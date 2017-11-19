#include <iostream>
#include <vector>

std::vector<int> maxSumArray(const std::vector<int> input)
{
	std::vector <int> result;
	if (input.size()==0)
		return result;

	auto maxSum = input[0];
	auto maxSoFar = input[0];
	auto startMax = 0;
	auto endMax = 0;
	for (size_t i = 1; i < input.size(); i++)
	{
		maxSoFar = std::max(maxSoFar+input[i], input[i]);
		if (maxSoFar == input[i])
		{
			startMax = i;

		}
		if (maxSoFar >= maxSum)
		{
			maxSum=maxSoFar;
			endMax=i; 
		}
	}

	for (auto i = startMax; i <= endMax; i++)
	{
		result.push_back(input[i]);
	}

	return result;
}

int main()
{
	//std::vector<int> input {-2, 1, -3, 4, -1, 2, 1, -5, 4}; 
	std::vector<int> input {-2, 1, -3, 4, -1, -2, 1, -5, 4}; 

	auto result = maxSumArray(input);

	for (auto x: result)
		std::cout << x << " ";

	std::cout << std::endl;

	return 0;

}
