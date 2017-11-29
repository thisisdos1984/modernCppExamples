#include <iostream>
#include <vector>

void PrintTable(const std::vector<std::vector<int>> & table)
{
	for (auto x : table)
	{
		for (auto y : x)
			std::cout << y << " " ;
		std::cout << std::endl;
	}
}

int LongestPalindromeSubsequece(const std::string &input)
{
	std::vector <std::vector <int>> table (input.size(), std::vector<int>(input.size(), 0));

	// len of palindrome for one character is one.
	for (size_t i = 0; i < input.size(); i++)
	{
		table[i][i] = 1;
	}

	for (size_t l = 1; l < input.size(); l++)
	{
		for (size_t i = 0; i < input.size() - l; i++)
		{
			int j = i + l;
			if (j - i == 1)
			{
				if (input[i] == input[j])
					table[i][j] = 2;
				else
					table[i][j] = 1;
			}
			else
			{
				if (input[i] == input[j])
					table[i][j] = table[i+1][j-1] + 2;
				else
					table[i][j] = std::max(table[i][j-1], table[i+1][j]);
			}
		}
	}
	PrintTable(table);

	return table[0] [input.size()-1];
}


int main()
{
	std::cout << "length of longest palindrome subsequence is :" << LongestPalindromeSubsequece("bbbab") << std::endl;
	std::cout << "length of longest palindrome subsequence is :" << LongestPalindromeSubsequece("GEEKS FOR GEEKS") << std::endl;
	return 0;
}



