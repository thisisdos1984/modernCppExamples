/*
 * program to add 2 linked lists 
 * each digit is one node of linked list in reverse order
 */


#include <iostream>
#include <vector>
#include <memory>

class SList
{
	struct _node 
	{
		int value;
		_node *next;

		_node (int value): value{value}, next{nullptr} { }

	} *m_root;

   public:

   	SList() : m_root {nullptr} { }
   	SList(std::vector<int>input);
	~SList();
   	void addNode(int value);
	std::shared_ptr<SList> sum (std::shared_ptr<SList> other);
	void print();

};

SList::SList(std::vector<int> input)
{
	for (auto x : input)
		addNode(x);
}

SList::~SList()
{
	auto tmpPtr = m_root;
	while (tmpPtr != nullptr)
	{
		delete tmpPtr;
		tmpPtr = tmpPtr->next;
	}
	m_root = nullptr;
}

// is this a correct prototype ?
std::shared_ptr<SList> SList::sum (std::shared_ptr<SList> other)
{
	std::shared_ptr <SList> sum (new SList());

	auto ptr1 = this->m_root;
	auto ptr2 = other->m_root;
	auto carry = 0;

	while (ptr1 != nullptr || ptr2 != nullptr)
	{
		
		auto addition = carry;
		if (ptr1 != nullptr)
		{
			addition += ptr1->value;
			ptr1 = ptr1->next;
		}
		if (ptr2 != nullptr)
		{
			addition += ptr2->value; 
			ptr2 = ptr2->next;
		}

		carry = addition / 10;
		addition = addition % 10 ;
		sum->addNode (addition);
	}
	if (carry != 0)
		sum->addNode (carry);


	return sum;
}
void SList::addNode(int value)
{
	auto newPtr = new _node(value);
	if (m_root == nullptr)
	{
		m_root = newPtr;
		return;
	}
	auto tmpPtr = m_root;

	while (tmpPtr->next != nullptr)
	{
		tmpPtr = tmpPtr->next;
	}

	tmpPtr->next = newPtr;

	return;
}

void SList::print()
{
	auto tmpPtr = m_root;
	while (tmpPtr != nullptr)
	{
		std::cout << tmpPtr->value << " ";
		tmpPtr = tmpPtr->next;
	}

	std::cout << std::endl;
}


int main()
{
	auto l1 = std::make_shared<SList> (std::vector<int>{1,2,3,4});
	auto l2 = std::make_shared<SList> (std::vector<int>{5,6,7,8,9});
	std::shared_ptr<SList> sum (l1->sum(l2));
	l1->print();
	l2->print();
	sum->print();
	return 0;
}



