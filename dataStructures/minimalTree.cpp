#include <iostream>
#include <vector>

class Btree
{
	struct Node 
	{
		int  _value;
		Node * _left;
		Node * _right;
		Node() {}
	};


	Node *root;
	void _preOrder(Node *root);
	Node* _createTreeHelper(const std::vector<int> &input, int low, int hight);
    public:
	void minimalTree(const std::vector<int> &input);

	void printTree();
};


Btree::Node* Btree::_createTreeHelper(const std::vector<int> &input, int low, int high)
{
	if (low > high)
		return nullptr;
	else
	{
		int mid = (low + high) / 2;
		Node *ptr = new Node();
		ptr->_value = input [mid];
		ptr->_left  = _createTreeHelper(input, low, mid - 1);
		ptr->_right = _createTreeHelper(input, mid + 1, high);
		return ptr;
	}

}

void Btree::minimalTree(const std::vector<int> &input)
{

	root = _createTreeHelper(input, 0, input.size() - 1);

}
void Btree::_preOrder(Btree::Node *root)
{
	if (root == nullptr)
		return;
	
	_preOrder(root->_left);
	std::cout << "node : " << root->_value << std::endl;
	_preOrder(root->_right);
	return;
}


void Btree::printTree()
{
	_preOrder(root);
}


int main()
{

	Btree t1;
	t1.minimalTree({1,2,3,4,5,6,7});

	t1.printTree();

	return 0;
}
