#include <iostream>
#include <vector>

int count = 0;
void printBoard(std::vector <std::vector <int>> &input)
{
	std::cout << "solution number : " << count << std::endl;
	for (auto x: input)
	{
		for (auto y : x)
			std::cout << y << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool isValid (std::vector <std::vector <int>> &input, int row, int col)
{
	// check row
	for (int i = 0; i < input.size(); i++)
		if (i != col && input[row][i] == 1)
			return false;

	// check col
	for (int i = 0; i < input.size(); i++)
		if (i != row && input[i][col] == 1)
			return false;

	// check cross 1

	for (int i = 0; i < input.size(); i++)
		for (int j = 0; j < input.size(); j++)
			if (i != row && j != col && (j - i) == (col - row))
				if (input[i][j] == 1)
					return false;
	// check cross 2

	for (int i = 0; i < input.size(); i++)
		for (int j = 0; j < input.size(); j++)
			if (i != row && j != col && (i + j) == (col + row))
				if (input[i][j] == 1)
					return false;

	return true;
}


bool solveQueensHelper(std::vector <std::vector <int>> &input, int row)
{
	if (row == input.size())
	{
		count ++;
		printBoard(input);
		return true;
	}
	for (int i = 0; i < input.size(); i++)
	{
		input[row][i] = 1;
		if (isValid (input, row, i))
		{
			solveQueensHelper(input, row+1);
		}
		input[row][i] = 0;
	}
	return false;
}


bool solveQueens(std::vector <std::vector<int>> &input)
{
	return solveQueensHelper(input, 0);
}

#define BOARD_SIZE 25

int main()
{
	std::vector <std::vector <int> > input(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));

	solveQueens(input);


	return 0;
}


