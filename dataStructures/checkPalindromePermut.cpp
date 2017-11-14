#include <iostream>
#include <string>
#include <unordered_map>

//	check if given string is a permutation of 
//	a palindrome. 
//	we just need to check if it has even number
//	of characters and just one odd numbered 
//	character in the string. 
//

bool checkPalinPermut(const std::string input)
{

	std::unordered_map<char, size_t> count;
	auto numOdd = 0;

	for (auto x : input)
	{
		if (std::isalpha(x))
		{
			count[std::tolower(x)] ++;

			if ( count[std::tolower(x)] % 2 ==1)
				numOdd ++;
			else
				numOdd --;
		}
	}

	if (numOdd == 0 || numOdd == 1)
		return true;
	else 
		return false;
}


int main()
{
	std::cout << checkPalinPermut("civic Tact coa") << std::endl;
	std::cout << checkPalinPermut("ciic Tact coa") << std::endl;
	return 0;
}


//g++  -std=c++11 -Wall -g  checkPalindromePermut.cpp
