#include <iostream>
#include <string>

using namespace std;


int count = 0;
void printPermut(string &input, int l, int r)
{
	cout << "count " << count++ << endl; 
	if (l==r)
		cout << input << endl;
	for (auto i = l; i < r; i++)
	{
		char temp = input[l];
		input[l] = input[i];
		input[i] = temp;

		printPermut (input, l+1, r);
		
		temp = input[l];
		input[l] = input[i];
		input[i] = temp;


	}

	
}


int main()
{

	string input = "ABC";
	printPermut (input, 0, input.size());

	return 0;

}


