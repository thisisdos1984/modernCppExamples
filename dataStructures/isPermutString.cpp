#include <iostream>
#include <string>
#include <array>
#include <vector>

bool isPermutation(std::string s1, std::string s2)
{
	// use vector instead of array because 
	// array will not be initialized with zeros
	std::array <int, 256> count {0};
	
    //std::vector<int> count (256, 0); 
    for (auto x : s1)
    {
        auto index = static_cast<size_t> (x);
        count[index] += 1;
    }

    for (auto x : s2)
    {
        auto index = static_cast<size_t> (x);
        count[index] -= 1;
    }

	for (auto x : count)
	{
		if (x < 0)
			return false;
	}

	return true;
}

int main ()
{

	std::cout << isPermutation("vinit", "iintw") << std::endl;
	std::cout << isPermutation("vinit", "iint") << std::endl;

    return 0;
}

// g++ -std=c++11 -Wall isPermutString.cpp
