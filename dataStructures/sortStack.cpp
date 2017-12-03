#include <iostream>
#include <stack>

/*
 * Sort the given stack using just another temporary stack
 * you are not allowed to use any other data structure like array
 *
 * The idea is to push items on temp stack in sorted order
 * and use original stack for temp space
 *
 */

void PrintStack(std::stack <int> input)
{
	while (!input.empty())
	{
		std::cout << input.top() << std::endl;
		input.pop();
	}
}


void SortStack (std::stack<int> &input)
{
	std::stack <int> temp;

	while (!input.empty())
	{
		int value = input.top();
		input.pop();

		while (!temp.empty() && temp.top() > value)
		{
			input.push(temp.top());
			temp.pop();
		}

		temp.push(value);
	}

	while (!temp.empty())
	{
		input.push(temp.top());
		temp.pop();
	}
}




void SortStackRecurse(std::stack<int> &input)
{

}


int main()
{

	std::stack<int> s;

	s.push( 2 );
	s.push( 51 );
	s.push( 6 );
	s.push( 25 );
	s.push( 12 );
	s.push( 18 );

	SortStack(s);


	PrintStack(s);

	return 0;
}


