#include <iostream>
#include <string>

// replace the spaces with "%20"
// actual size is provided


void replaceSpace(std::string &input, size_t actualSize)
{
	auto i = actualSize - 1;
	auto j = input.size() - 1;

	while(i > 0 || j > 0)
	{
		if (input[i] == ' ')
		{
			input[j--] = '0';
			input[j--] = '2';
			input[j--] = '%';
			i--;

		}
		else 
		{
			input[j--] = input[i--];
		}
	}
}


int main()
{

	std::string input = "Mr John Smith    ";
	replaceSpace(input, 13);
	std::cout << input << std::endl;
	return 0;
}
