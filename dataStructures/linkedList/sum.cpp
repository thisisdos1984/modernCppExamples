/*
 * program to add 2 linked lists 
 * each digit is one node of linked list in reverse order
 */
#include <iostream>
#include <vector>
#include <memory>
#include <stack>

class SList
{
	struct _node 
	{
		int value;
		_node *next;

		_node (int value): value{value}, next{nullptr} { }

	} *m_root, *m_current;

	int _reverseSumRecurse (std::shared_ptr<SList> sum, const _node *n1, const _node *n2);
   public:

   	SList() : m_root {nullptr}, m_current{nullptr} { }
   	SList(const std::vector<int> &input);
	~SList();
   	void addNode(int value);
	void print();

	std::shared_ptr<SList> sum (std::shared_ptr<SList> other);
	std::shared_ptr<SList> reverseSum (std::shared_ptr<SList> other);
	std::shared_ptr<SList> reverseSumRecurse (std::shared_ptr<SList> other);

};

SList::SList(const std::vector<int> &input)
{
	for (auto x : input)
		addNode(x);
}

SList::~SList()
{
	while (m_root != nullptr)
	{
		auto tmpPtr = m_root;
		m_root = m_root->next;
		delete tmpPtr;
	}
	m_root = nullptr;
	m_current = nullptr;
}

int SList::_reverseSumRecurse (std::shared_ptr<SList> sum, const _node *n1, const _node *n2)
{
	if (n1 == nullptr && n2 == nullptr)
		return 0;
	
	auto carry = _reverseSumRecurse(sum, n1 == nullptr ? nullptr : n1->next, n2==nullptr ? nullptr : n2->next);
	auto addition = carry + (n1== nullptr ? 0 : n1->value) + (n2 == nullptr ? 0 : n2->value);
	carry = addition / 10;
	addition = addition % 10 ;

	sum->addNode (addition);
	return carry; 

}
std::shared_ptr<SList> SList::reverseSumRecurse (std::shared_ptr<SList> other)
{
	auto sum = std::make_shared<SList> ();
	auto carry = _reverseSumRecurse(sum, this->m_root, other->m_root);
	sum->addNode(carry);
	return sum;
}
std::shared_ptr<SList> SList::reverseSum (std::shared_ptr<SList> other)
{
	auto sum = std::make_shared<SList> ();
	std::stack<_node *> st1;
	std::stack<_node *> st2; 
	std::stack<int> result; 

	auto ptr1 = this->m_root;
	auto ptr2 = other->m_root;
	auto carry = 0;

	while (ptr1 != nullptr || ptr2 != nullptr)
	{
		if (ptr1 != nullptr)
		{
			st1.push(ptr1);
			ptr1 = ptr1->next;
		}
		if (ptr2 != nullptr)
		{
			st2.push(ptr2);
			ptr2= ptr2->next;
		}
	}
	while (!st1.empty() || !st2.empty())
	{
		auto addition = carry;
		if (!st1.empty())
		{
			addition += st1.top()->value;
			st1.pop();
		}
		if (!st2.empty())
		{
			addition += st2.top()->value;
			st2.pop();
		}
		carry = addition / 10;
		addition = addition % 10 ;
		result.push (addition);
	}
	if (carry != 0)
		result.push (carry);

	while (!result.empty())
	{
		sum->addNode(result.top());
		result.pop();
	}

	return sum; 

}

// is this a correct prototype ?
std::shared_ptr<SList> SList::sum (std::shared_ptr<SList> other)
{
	auto sum = std::make_shared <SList> ();

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
		m_current = m_root = newPtr;
		return;
	}

	m_current->next = newPtr;
	m_current = m_current->next;

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
	std::shared_ptr<SList> sum (l1->reverseSumRecurse(l2));
	l1->print();
	l2->print();
	sum->print();
	return 0;
}

