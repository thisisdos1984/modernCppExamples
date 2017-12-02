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
	Queue(const Queue & other);
	Queue(Queue && other);        // remember: no const other object because it is being moved

	Queue& operator=(const Queue &other);
	Queue& operator=(Queue &&other);

	~Queue() {}
	
	
	void Enqueue(int value);
	bool IsEmpty();
	int Dequeue();

};
// move assignment 
Queue& Queue::operator=(Queue &&other)
{
	std::cout << "move-assign the queue" << std::endl;
	if (&other != this)
	{
		active  = std::move(other.active);
		passive = std::move(other.passive);
	}
	return *this;
}

//copy assignment 
Queue& Queue::operator=(const Queue &other)
{
	std::cout << "copy-assign the queue" << std::endl;
	if (&other != this)     // to handle q1=q1
	{
		active.reset (new std::stack<int>(*other.active));
		passive.reset (new std::stack<int>(*other.passive));
	}
	return *this;
}

//move constructor
Queue::Queue(Queue && other): active(std::move(other.active)), passive(std::move(other.passive))
{
	std::cout << "moving the queue" << std::endl;
}

//copy constructor
Queue::Queue(const Queue & other) : active (new std::stack<int>(*other.active)), passive (new std::stack<int>(*other.passive))
{
	std::cout << "copying the queue" << std::endl;
}

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
	Queue q1;		//default 
	Queue q2(q1);   	//copy
	Queue q3 (std::move(q2)); // move constructor


	Queue Q4;
	Queue Q5; 
	Queue Q6;

	Q4 = Q5; 		//copy assignment
	Q5 = std::move(Q6);	//move assignment

	

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

