#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

void slidingMax(const vector<int>& input, size_t window, vector<int>& output)
{
	if (window > input.size())
		return;

	deque<pair<int, size_t>> mapQ; 

	for (decltype(window) i = 0; i < window; i++)
	{
		while ((!mapQ.empty() && input[i] > mapQ.back().first))
			mapQ.pop_back();
		
		auto p1 = make_pair(input[i], i);
		mapQ.push_back(p1);
	}

	for (auto i = window; i < input.size(); i++)
	{
		output.push_back(mapQ.front().first);
		
		while ((!mapQ.empty() && input[i] > mapQ.back().first))
			mapQ.pop_back();

		while ((!mapQ.empty() && (i - mapQ.front().second >= window)))
			mapQ.pop_front();


		auto p1 = make_pair(input[i], i);
		mapQ.push_back(p1);
	}
	output.push_back(mapQ.front().first);
}

void heapify(std::vector<int>& input, int pos, int len)
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

		heapify (input, swap, len);
	}

}


void slidingMaxHeap(const vector<int>& input, size_t window, vector<int>& output)
{

	for (auto slide = 0; slide < input.size() - window; slide++)
	{
		vector <int> heap;
		for (auto i = slide; i < slide + window && i < input.size(); i++)
		{
			heap.push_back(input[i]);
		}

		for (int i = (heap.size()/2 - 1); i >= 0; i--)
			heapify(heap, i, heap.size());
		
		output.push_back(heap[0]);
	}
}



int main ()
{

	const vector<int> input {1, 3, -1, -3, 5, 3, 6, 7, 1, 2, 3, 4, 5, -1, -2, -3};
	vector<int> output;
	auto window = 3;

	slidingMaxHeap(input, window, output);

	for (auto x : output)
		cout << x << " ";
	cout << endl;

	return 0;
}
