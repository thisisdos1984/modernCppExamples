#include <atomic>

class B
{
	//non-copyable, non-movable member 

	std::atomic <bool> x;
public:
	B()
	{
	}
	B(const B &other)
	{

	}

};

int main ()
{
	B b;        	// OK
	B c = b;		//compilation error if no copy constructor defined


	return 0;
}
