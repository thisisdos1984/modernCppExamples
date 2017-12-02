#include <iostream>
#include <stack>
#include <memory>
#include <algorithm>


/* Implement queue using 2 stacks
 * We need to move elements from one stack
 * to another on each dequeue operation.
 */

class Queue
{

	std::unique_ptr<std::stack <int>> active;
	std::unique_ptr<std::stack <int>> passive;


   public:
	Queue() : active(new std::stack<int>()), passive(new std::stack<int>()) {}
	~Queue() {}
	void Enqueue(int value);
	bool IsEmpty();
	int Dequeue();

};


/* 
 * push elements on active stack for enqueue operation 
 */

void Queue::Enqueue(int value)
{
	active->push(value);
	//std::swap(active, passive);
}

/* while removing items from queue
 * use passive queue to reverse the 
 * order of elements 
 */

int Queue::Dequeue()
{
	if (passive->empty())
	{
		while ( !active->empty() )
		{
			passive->push(active->top());
			active->pop();
		}
	}

	int ret = passive->top();
	passive->pop();
	return ret;
}

bool Queue::IsEmpty()
{
	return (active->empty() && passive->empty());
}


int main()
{
	Queue q1;
	// Queue q2(q1);   // compilation error due to deleted copy constructor
	
	Queue q2;
	//q2 = q1;         // compilation error due to deleted = operator

	q1.Enqueue(5);
	q1.Enqueue(6);
	
	q1.Dequeue();
	
	q1.Enqueue(7);
	q1.Enqueue(8);
	q1.Enqueue(9);

	while (!q1.IsEmpty())
		std::cout << q1.Dequeue() << std::endl;
	return 0;
}

