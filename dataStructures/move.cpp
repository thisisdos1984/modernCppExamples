#include <iostream>

using namespace std;

class MyMove 
{
	int a;
	string myName;

public:

	MyMove()
	{
		cout << "default constructor" << endl;
	}
	~MyMove()
	{
		cout << "destructor" << endl;
	}

	MyMove(const MyMove & other)
	{
		this->a = other.a;
		cout << "copy constructor" << endl;

	}
	MyMove(const MyMove && other)
	{
		this->a = other.a;
		cout << "move constructor" << endl;

	}
	MyMove & operator= (const MyMove & other)
	{
		if (this != &other)
		{
			cout << "copy equal operator" << endl;
		}
		return *this;

	}
	MyMove & operator= (const MyMove && other)
	{
		if (this != &other)
		{
			cout << "move equal operator" << endl;
		}
		return *this;

	}


};


int main()
{
	MyMove m;
	MyMove n(std::move( m));
	MyMove x ;
	x = std::move(m);

	return 0;
}

