#include <iostream>
#include <memory>
#include <vector>
//stack using linked list 
class Stack 
{
	struct _node 
	{
		int value;
		std::shared_ptr<_node> preNode;
		std::shared_ptr<_node> minNode;
		_node (int value, std::shared_ptr<_node> min): 
				value {value}, preNode{nullptr}, minNode{min} {}

		~_node() { std::cout << "In Node destrustor" << std::endl; }

	};

	std::shared_ptr <_node> m_top, m_min;
	int len; 

  public:
  	Stack() : m_top {nullptr}, m_min{nullptr}, len{0} {}
	Stack(const std::vector<int> &input);
	~Stack();

	void Push(int value);
	int  Pop();
	bool Empty();
	int  Front();
	int  GetMin();

};

Stack::Stack(const std::vector<int> &input)
{
	for (auto x : input)
		Push(x);
}

Stack::~Stack()
{
	std::cout << "In destructor" << std::endl;
	while (!Empty())
		Pop();
}

void Stack::Push(int value)
{
	auto nodePtr = std::make_shared <_node> (value, m_min);
	nodePtr->preNode = std::move(m_top);
	m_top = std::move(nodePtr);
	len++;

	if (m_min == nullptr)
		m_min = m_top;
	else
		if(m_top->value < m_min->value)
			m_min = m_top;
	return;
}

int Stack::Pop()
{
	auto newTop = m_top->preNode;
	if (m_top == m_min)
		m_min = m_top->minNode;
	
	auto topValue = m_top->value;
	m_top.reset();    // this will delete the _node object 
	m_top = std::move(newTop);
	len--;
	return topValue;
}

bool Stack::Empty()
{
	if (m_top != nullptr)
		return false;
	else
		return true;
}
int Stack::Front()
{
	return m_top->value;
}

int Stack::GetMin()
{
	return m_min->value;
}

int main()
{
	const std::vector<int> input {4,7,9, 2,23,1, 6,7,9};

	std::unique_ptr <Stack> p1 (new Stack(input));
	std::unique_ptr <Stack> p2 (new Stack(input));


	while (!p1->Empty())
	{
		std::cout << p1->GetMin() << " ";
		p1->Pop();
	}

	std::cout << std::endl;

	Stack s1 ({1});
	std::cout << s1.GetMin() << std::endl;	
	return 0;
}

