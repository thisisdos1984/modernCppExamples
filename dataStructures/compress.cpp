#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

//function to compress the input string
//replace repeated chars with its count


std::string compress(const std::string &input)
{
	std::string output; 

	auto prev = input[0];
	auto count = 0;

	for (auto x : input)
	{
		if (prev != x)
		{
			output.push_back(prev);
			output.append(std::to_string(count));
			count = 0;
		}
		count ++;
		prev = x;
	}
	output.push_back(prev);
	output.append(std::to_string(count));
	
	if (output.size() < input.size())
		return output;
	else
		return input;
}


int main()
{
	std::string input {"aabcccccaaasdffse"};
	
	std::cout << compress(input) << std::endl;
	std::cout << compress("aabcccccaaaaaa") << std::endl;
	
	return 0;	
}


//g++  -std=c++11 -Wall -g compress.cpp
