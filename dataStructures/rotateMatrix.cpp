#include <iostream>
#include <vector>


void rotateMatrix(std::vector<std::vector<int>> &input)
{
	auto size = input.size();

	for (size_t i=0; i<size/2; i++)
		for (size_t j=i; j < size-i; j++)
		{
			auto temp = input[j][size-i-1];
			input[j][size-i-1] = input[i][j];
			input[i][j] = temp;

			std::cout << "swapped" << input[i][j] << " " << input[j][size-i-1] << std::endl;
		}
}


int main()
{
	std::vector<std::vector<int>> input {{1 ,2, 3, 4, 5}, 
										 {6 ,7, 8, 9, 0},
										 {11,12,13,14,15},
										 {16,17,18,19,20},
										 {21,22,23,24,25}};

	rotateMatrix(input);

	for(auto x : input)
	{
		for (auto y : x)
			std::cout << y << " ";

		std::cout << std::endl;
	}



	return 0;
}
