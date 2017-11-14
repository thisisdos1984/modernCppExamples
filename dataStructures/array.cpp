#include <iostream>
#include <array>
#include <algorithm>
#include <typeinfo>
#include <string>
#include <list>

using namespace std;

typedef std::array<string, 100> myStrings;
typedef std::array<int, 100> myArray;

int main ()
{

	std::list<int> a {4,9,6,1,8,0};

	auto i = 2;
	i++;
	constexpr auto size = 10;
	int j[size] {1, 2, 3}; 

	myStrings s {"vinit", "hello"};

	a.sort();

//	cout << a << endl;

	for (auto &x : a)
	{
		cout << x << endl;
	}
	for (auto &x : j)
	{
		cout << x << endl;
	}

	cout << typeid(a).name() << endl;
	return 0;
}
