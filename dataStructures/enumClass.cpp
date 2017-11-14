#include <iostream>
using namespace std;

enum class color { RED, BLUE, BLACK };

int main ()
{
	color x = color::BLACK;

	auto i = static_cast<int> (x);
	cout << static_cast<int>(color::RED) << endl; 
	cout << i << endl; 
	return 0;
}
