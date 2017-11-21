#include <iostream>
#include <vector>

typedef const std::vector<int> const_int;


void printMatrix(const std::vector <std::vector<int>> &input)
{
	for (auto &x : input)
	{
		for (auto &y : x)
			std::cout << y << " ";
		std::cout << std::endl;
	}
}


void zeroRow(std::vector <std::vector<int>> &input, int index)
{
	for (size_t i = 0; i < input[index].size(); i++)
		input[index][i] = 0;
}
void zeroCol(std::vector <std::vector<int>> &input, int index)
{
	for (size_t i = 0; i < input.size(); i++)
		input[i][index] = 0;
}


void zeroMatrix(std::vector <std::vector<int>> &input)
{
	auto rowHasZero = false, colHasZero = false;

	//identify if first row has any zeros 
	for (auto &x : input[0])
		if (x == 0)
			rowHasZero = true;

	//identify if first col has any zeros 
	for (auto &x : input)
		if (x[0] == 0)
			colHasZero = true;

	//set elements from first row and first col 
	//to zero if zero is found
	for (size_t i = 1; i < input.size(); i++)
	{
		for (size_t j = 1; j < input[i].size(); j++)
		{
			if (input[i][j] == 0)
			{
				input[i][0] = 0;
				input[0][j] = 0;
			}
		}
	}

	for (size_t i = 1; i < input.size(); i++)
		if (input[i][0] == 0)
			zeroRow(input, i);

	for (size_t i = 1; i < input[0].size(); i++)
		if (input[0][i] == 0)
			zeroCol(input, i);

	if (rowHasZero)
		zeroRow(input, 0);

	if (colHasZero)
		zeroCol(input, 0);
}


int main()
{
	std::vector<std::vector<int>> input {{1,2,0,4},
					     {5,6,7,8},
					     {9,0,1,2},
					     {0,4,5,6},
					     {7,8,9,0},
						};

	zeroMatrix(input);
	printMatrix(input);

	std::cout << std::endl;
	std::vector<std::vector<int>> input2 {{1,2,0,4},
						};
	zeroMatrix(input2);
	printMatrix(input2);


	std::cout << std::endl;
	std::vector<std::vector<int>> input3 {{1},
						{2},
						{2},
						{2},
						{2},
						{2},
						{2},
						{2},
						{2},
						{2},
						};
	zeroMatrix(input3);
	printMatrix(input3);

	return 0;
}



