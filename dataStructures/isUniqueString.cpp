#include <iostream>
#include <unordered_set>
bool isUnique(std::string input)
{
	std::unordered_set <char> set; 
	for (auto x : input)
	{
		if (set.find(x) != set.end())
			return false;
		set.insert(x);
	}
	return true;

}



int main()
{
	std::cout << isUnique("vinit") << std::endl;
	return 0;
}
