
#include <iostream>
#include <vector>

void printInput(const std::vector<int>& input)
{
	for (auto x : input)
		std::cout << x << " ";
	std::cout << std::endl;
	
}

void maxHeapify(std::vector<int>& input, int pos, int len)
{
	auto swap = pos;
	auto left = 2*pos + 1;
	auto right = 2*pos + 2;

	if (left < len && input[pos] < input[left])
		swap = left;
	if (right < len && input[swap] < input[right] )
		swap = right;

	if (swap != pos)
	{
		auto temp = input[pos];
		input [pos] = input [swap];
		input [swap] = temp;

		maxHeapify (input, swap, len);
	}
}

void heapSort(std::vector<int>& input)
{
	//build the heap

	for (int i = (input.size()/2 - 1); i >= 0; i--)
	{
		maxHeapify(input, i, input.size());
	}

	// swap max element and then heapify

	for (int i = input.size()-1; i >=0; i-- )
	{
		auto temp = input[0];
		input[0] = input[i];
		input[i] = temp;

		maxHeapify(input, 0, i);
	}
}




int main()
{
	std::vector <int> input {9, 0, 100, 44, 22, 77, 1, 2, 3, 4, 5, 6, 7, 8};

	heapSort(input);

	printInput(input);

	return 0;
}
