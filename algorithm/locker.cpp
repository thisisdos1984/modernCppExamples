#include <iostream>
#include <vector>

void lockerPass(std::vector <char>& input)
{
	for (int i = 1; i <= 100; i++)
	{
		for (int j = i-1; j < 100; j += i)
		{
			input[j] = ((input[j] == 'l') ? 'u' : 'l');
		}
	}
}


int main()
{

	std::vector <char> input (100, 'l');


	lockerPass(input);

	int i = 1;
	for (auto x : input)
	{
		std::cout << i << x << std::endl;
		i++;
	}
	std::cout << std::endl;
}
