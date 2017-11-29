#include <iostream>
#include <string>
#include <vector>

void PrintTable(const std::vector<std::vector<bool>> & table)
{
	for (auto x : table)
	{
		for (auto y : x)
			std::cout << y << " " ;
		std::cout << std::endl;
	}
}
void PrintAllPalindromes(const std::string &input, const std::vector<std::vector<bool>> &table)
{
	for(size_t i = 0; i < table.size(); i++)
	{
		for (size_t j = 0; j < table[i].size(); j++)
		{
			if (i != j && table[i][j] == true)
			{
				std::cout << std::string (input.begin()+i, input.begin()+j+1) << std::endl;
			}
		}
	}
}


std::string LongestPalindromeSubstring(const std::string & input)
{
	std::vector <std::vector <bool>> table (input.size(), std::vector<bool>(input.size(), false));

	int max_i = 0, max_j = 0;

	for (size_t i = 0; i < input.size(); i++)
	{
		table[i][i] = true;
	}

	for (size_t l = 1; l < input.size(); l++)
	{
		for (size_t i = 0; i < input.size() - l ; i++)
		{
			auto j = i + l;
			if (input[i] == input[j])
			{
				if (j - i == 1)
				{
					table[i][j] = true;
					max_i = i;
					max_j = j;
				}
				else
				{
					if (table[i+1][j-1] == true)
					{
						table[i][j] = true;
						max_i = i;
						max_j = j;
					}
				}
			}
		}
	}

	PrintTable(table);
	PrintAllPalindromes(input, table);

	std::string output (input.begin() + max_i, input.begin() + max_j + 1);

	return output;
}


int main()
{
	std::string input = "forgeeksskeegfor";
	//std::string input = "geaaekaabaa";

	LongestPalindromeSubstring(input);

	LongestPalindromeSubstring("bananas");
	return 0;
}
