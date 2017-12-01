#include <iostream>
#include <vector>

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


int minCoins(const std::vector <int> & coins, int sum)
{
	std::vector <std::vector <int>> table (coins.size(), std::vector <int>(sum+1, 0));


	for (size_t row = 0; row < coins.size(); ++row)
	{
		for (int col = 0; col <= sum; ++col)
		{
			if (row == 0 && col == 0)
			{
				table[row][col] = 0;
				continue;
			}

			if (coins[row] > col)
			{
				table [row][col] = table[row-1][col];
			}
			else
			{
				table [row][col] = table[row][col-coins[row]] + 1;
			}
		}
	}
	PrintTable(table);
	return table[coins.size()-1][sum];
}

int main()
{

	std::cout << minCoins({1, 3, 4}, 6) << std::endl;

	return 0;
}


