#include <iostream>
#include <vector>

const int NUM_ROWS = 9;
const int NUM_COLS = 9;
const int MAX_NUMS = 9;

/* 
 * Class to solve sudoku puzzle
 *
 */

class Sudoku
{
	//The board of 9x9 vectors
	std::vector <std::vector<int>> board_;

	//helper functions 

	std::vector<int> GetPossibleNumbers(int row, int column);
	bool IsPresentInRow(int row, int num);
	bool IsPresentInColumn(int col, int num);
	bool IsPresentInSubMatrix(int row, int col, int num);
  public:

	Sudoku() = delete;  // not needed, but keep it for completeness
	Sudoku(const std::vector <std::vector <int>>& input) : board_{input} {}
	Sudoku(const Sudoku &other) : board_ {other.board_} {}
	Sudoku(const Sudoku &&other) : board_ {std::move(other.board_)} {}

	void PrintBoard();
	bool Solve();

};


void Sudoku::PrintBoard()
{
	for (auto x : board_)
	{
		for (auto y : x)
			std::cout << y << " ";
		std::cout << std::endl;
	}
}
bool Sudoku::IsPresentInRow(int row, int num)
{
	for (int i = 0; i < NUM_ROWS; i++)
		if (board_[row][i] == num)
			return true;

	return false;

}
bool Sudoku::IsPresentInColumn(int col, int num)
{
	for (int i = 0; i < NUM_COLS; i++)
		if (board_[i][col] == num)
			return true;

	return false;

}

bool Sudoku::IsPresentInSubMatrix(int row, int col, int num)
{
	// starting coordinates of the sub matrix
	auto start_i = row - row % 3;
	auto start_j = col - col % 3;

	for (int i = start_i; i < start_i + 3; i ++)
		for (int j = start_j; j < start_j + 3; j++)
			if (board_[i][j] == num)
				return true;

	return false;

}

std::vector<int> Sudoku::GetPossibleNumbers(int row, int column)
{
	std::vector <int> output;

	for (int i = 1; i <= MAX_NUMS; i++)
	{
		if (!IsPresentInRow(row, i) && !IsPresentInColumn(column, i) && !IsPresentInSubMatrix(row, column, i))
			output.push_back(i);
	}

	return output;
}

bool Sudoku::Solve()
{
	for (int i = 0; i < NUM_ROWS; ++i)
	{
		for (int j = 0; j < NUM_COLS; ++j)
		{
			if (board_[i][j] == 0)
			{
				bool is_found = false;
				for (auto x : GetPossibleNumbers(i, j))
				{
					board_[i][j] = x;

					if (false == Solve())
					{
						//backtrack 
						board_[i][j] = 0;
						continue;
					} 
					else
					{
						is_found = true;
						break;
					}
				}
				if (is_found)
					continue;
				else
					return false;

			}
	
		}
	}
	return true;
}


int main() {

	const std::vector <std::vector <int>> input = {{2,0,0,0,9,0,0,3,1},
            {0,0,3,5,0,6,0,2,0},
            {0,0,8,1,3,0,5,4,0},
            {7,2,0,0,0,9,0,0,4},
            {4,0,0,0,0,0,0,0,8},
            {3,0,0,6,0,0,0,9,5},
            {0,7,6,0,4,5,1,0,0},
            {0,1,0,9,0,7,4,0,0},
            {5,3,0,0,8,0,0,0,6}};

	
	Sudoku s1 (input);
	Sudoku s2 (s1);

//	Sudoku s3;	compilation error;
	
	s1.PrintBoard();
	std::cout << std::endl;

	s1.Solve();

	s1.PrintBoard();

	return 0;

}


