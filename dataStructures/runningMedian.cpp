
/* 
 * Given that integers are read from a data stream. Find median of 
 * elements read so far in efficient way. 
 * Making it clear, when the input size is odd, we take 
 * the middle element of sorted data. If the input size is even, we
 * pick average of middle two elements in sorted stream.
 *
 */

#include <iostream>
#include <algorithm>
#include <queue>  
#include <functional>


// use using instead of typedef .. much easier and cleaner 

using minHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>;
using maxHeap = std::priority_queue<int>;


class RunningMedian
{
	maxHeap left;
	minHeap right;

   public:
	void 	InsertValue(int input);
	double  GetMedian ();
};


void RunningMedian::InsertValue(int input)
{
	if (left.size() == right.size())
		left.push(input);
	else 
		if (left.size() > right.size())
			right.push(input);
		else
			left.push(input);

}

double RunningMedian::GetMedian()
{
	if (left.size() == 0 && right.size() == 0)
		return 0;

	if (left.size() == right.size())
		return ((double)left.top() + (double)right.top()) / 2;
	else
		return ( left.size() > right.size() ? left.top() : right.top() );
}


int main()
{
	// stl provides way to heapify your vector -- sample :) 
	std::vector <int> a {8,2,5,0,4,1,3};
	make_heap(a.begin(), a.end());


	//actual usage of running median

	std::vector <int> input;
	RunningMedian m1;

	std::cout << ":" <<  m1.GetMedian() << std::endl;


	for (auto x : {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4})
	{
		input.push_back(x);
		m1.InsertValue(x);

		for (auto i : input) std::cout << i << " "; 

		std::cout << ":" <<  m1.GetMedian() << std::endl;
	}

	return 0;
}
