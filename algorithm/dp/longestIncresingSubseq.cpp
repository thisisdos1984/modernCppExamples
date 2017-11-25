#include <iostream>
#include <vector>
#include <array>

std::vector<int> longestIncresing(const std::vector<int> input)
{
	std::vector<int> len (input.size());
	std::vector<int> output;

	for (int i = 0; i < (int) input.size(); i++)
	{
		len[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (input[i] > input[j])
			{
				if (len[j] + 1 > len[i])
					len[i] = len[j] + 1;
			}
		}
		for (auto x: len)
			std::cout << x << " " ; 

		std::cout << std::endl;
	}

	auto max = 0;
	auto maxIndex = 0;
	for (int i = 0; i < (int )len.size(); i++)
		if (len[i] > max)
		{
			max = len[i];
			maxIndex = i; 
		}

	output.insert(output.begin(), input[maxIndex]);
	for (int i = maxIndex; i >= 0; i--)
	{
		if (len[i] == max - 1)
		{
			output.insert(output.begin(), input[i]);
			max = len[i];
		}
	}
	return output;

}
int maxSum(const std::vector<int> input)
{
	auto max = input[0];
	auto maxSoFar = input [0];
	for (int i = 1; i < (int) input.size(); i++)
	{
		max = max + input[i];
		if (input[i] > max)
		{
			max = input[i];
		}
		if (max > maxSoFar)
		{
			maxSoFar = max; 
		}

	}
	return maxSoFar; 
}

int main()
{
	//std::vector<int> input {5,7,4,-3,9,1,10,4,5,8,9,3,4, 5, 8, 9,0};
	//std::vector <int> input { 1, 12, 7, 0, 23, 11, 52, 31, 61, 69, 70, 2 };
	std::vector<int> input {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	for (auto x: input)
		std::cout << x << " " ; 
	std::cout << std::endl;

	auto output = longestIncresing(input) ;
	for (auto x: output)
		std::cout << x << " " ; 
	std::cout << std::endl;

	std::cout << maxSum(input) << std::endl;
	return 0;
}
