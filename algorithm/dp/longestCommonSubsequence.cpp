#include <iostream>
#include <vector>
#include <algorithm>

// print the answer table

void PrintTable(const std::vector<std::vector<int>> & table)
{
	for (auto x : table)
	{
		for (auto y : x)
			std::cout << y << " " ;
		std::cout << std::endl;
	}
}

/* longest common subsequence
 * build the answer table
 */

std::string LongestCommonSubsequence(const std::string & s1, const std::string & s2)
{
	std::vector <std::vector <int> > table (s1.size() + 1, std::vector<int> (s2.size() + 1, 0));

	for (size_t row = 0; row <= s1.size(); ++row)
	{
		for (size_t col = 0; col <= s2.size(); ++col)
		{
			if (col == 0 || row == 0)
			{
				table[row][col] = 0;
				continue;
			}

			if (s1[row - 1] == s2[col - 1])
				table[row][col] = table [row-1][col-1] + 1;
			else
				table[row][col] = std::max(table[row-1][col], table[row][col-1]);

		}
	}

	PrintTable(table);

	size_t row = s1.size() + 1;
	size_t col = s2.size() + 1;
	std::string result ;

	while (row != 0 && col != 0)
	{
		if (s1[row-1] == s2[col - 1])
		{
			result.insert(0, 1, s1[row-1]);
			row --;
			col --;
		}else 
		{
			if (table[row-1][col] > table[row][col-1])
				row --;
			else
				col --;
		}
			
	}

	return result;
}

/* implement longest palindromic subsequence using 
 * longest common subsequence of the input with its 
 * reverse string.
 */

std::string LongestPalindromeSubsequence (const std::string &input)
{
	std::string rev = input;

	std::reverse(rev.begin(), rev.end());

	return LongestCommonSubsequence(input, rev);

}


int main()
{
	std::cout << LongestCommonSubsequence("AGGTAB", "GXTXAYB") << std::endl;
	std::cout << LongestPalindromeSubsequence("GEEKSFORGEEKS") << std::endl;
	std::cout << LongestPalindromeSubsequence("bbbab") << std::endl;
	return 0;
}
