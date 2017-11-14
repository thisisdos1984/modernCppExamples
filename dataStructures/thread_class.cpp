#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;


class myThread 
{
	int work;
	thread t1;
	std::mutex lock;
	std::condition_variable cv;


	int workerThread()
	{
		cout << std::this_thread::get_id() << endl ;
		cout << "number of threads : " << std::thread::hardware_concurrency() << endl;
		cout << "work " << work << endl;
		std::unique_lock <std::mutex> locker (lock);
		cv.wait(locker);
		return 0;
	}


public:
	myThread(): work{0}, t1{ &myThread::workerThread, this } {	cout << "default constructor" << endl; }

	~myThread ()
	{
		t1.join();
	}


};


int main ()
{
	myThread t1;

	return 0;

}


