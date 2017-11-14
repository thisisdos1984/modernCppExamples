#include <iostream>
#include <cstring>
#include <memory>


using namespace std;


class rule_of_five 
{

	char *ptr;
 public:
 	rule_of_five()
	{
		cout << "default constructor" << endl;
		ptr = nullptr;
	}
	rule_of_five(const char *input)
	{
		cout << "non default constructor" << endl;
		ptr = new char[std::strlen(input)];
		std::strcpy(ptr, input);
	}


	rule_of_five(const rule_of_five &other)
	{
		cout << "copy constuctor" << endl;
		ptr = new char[std::strlen(other.ptr)+1];
		std::strcpy(ptr, other.ptr);

	}

	rule_of_five(rule_of_five && other)
	{
		cout << "move constuctor" << endl;
		ptr = other.ptr;
		other.ptr = nullptr;
	}


	rule_of_five& operator=(const rule_of_five &other)
	{
		cout << "copy operator" << endl;
		if(this != &other)
		{
			ptr = new char[std::strlen(other.ptr)+1];
			std::strcpy(ptr, other.ptr);
		}
		return *this;
	}
	rule_of_five& operator=(rule_of_five &&other)
	{
		cout << "move operator" << endl;
		if(this != &other)
		{
			ptr = other.ptr;
			other.ptr = nullptr;
		}

		return *this;
	}

	~rule_of_five()
	{
		cout << "destructor" << endl;
		if (ptr != nullptr)
			delete ptr;
	}
	

};


int main()
{
	rule_of_five x { "hello world" };

	rule_of_five *y = new rule_of_five(std::move(x));

	
	rule_of_five a { "hello world" };
	rule_of_five b;

	b = std::move(a);

	//auto ptr = std::make_unique<rule_of_five> ();

	cout << "unique ptr" << endl;
	{
		unique_ptr<rule_of_five> ptr(new rule_of_five());
	}

	cout << "uniq" << endl ;

	{
		unique_ptr<rule_of_five> ptr (y);
	}


	cout << "unique ptr" << endl;


	delete y;
	return 0;
}
