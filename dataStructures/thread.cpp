#include <iostream>
#include <thread>

using namespace std;

void foo()
{

	cout << "in thread " << std::this_thread::get_id() << endl;
	
}


int main ()
{

	std::thread t1 {foo}; 
	
	cout << "in thread " << std::this_thread::get_id() << endl;

	std::this_thread::sleep_for(std::chrono::seconds(2));
	t1.join();
	return 0;

}
