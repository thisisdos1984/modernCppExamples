#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>


using namespace std;

struct Node 
{
	int value = 0;
	Node *left = nullptr;
	Node *right= nullptr;

};

class BTree
{
	Node* m_root;
	void _preOrder(Node *root);
	void _preOrderDelete(Node *root);
	int  _calcWidth(Node *root, int distance);
  public:

	BTree(): m_root{nullptr} { }
	~BTree();


	void addNode(int value);
	void displayTree();

	void levelPrint();
	int calcWidth();

	void convertToList();
	void displayList();

};


BTree::~BTree()
{
	cout << "in destructor" << endl; 
	_preOrderDelete(m_root);
	m_root = nullptr;
}


void BTree::addNode (int value)
{

	auto newNode = new Node;
	newNode->value = value;

	if (m_root == nullptr)
	{
		m_root = newNode;
	} 
	else
	{
		auto curr = m_root;
		auto prev = m_root;

		while (curr)
		{
			prev = curr;
			if (curr->value > value)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if (prev->value > value)
			prev->left = newNode;
		else
			prev->right = newNode;

	}

}

void BTree::_preOrderDelete(Node *root)
{
	if (root == nullptr)
		return;
	
	_preOrderDelete(root->left);
	_preOrderDelete(root->right);

	delete root;
	return;
}

void BTree::_preOrder(Node *root)
{
	if (root == nullptr)
		return;
	
	_preOrder(root->left);
	cout << "node : " << root->value << endl;
	_preOrder(root->right);
	return;
}

void BTree::levelPrint()
{
	if (m_root == nullptr)
		return;


	queue<Node *> levelQueue;
	levelQueue.push(m_root);
	levelQueue.push(nullptr);
	auto level = 0;

	while(!levelQueue.empty())
	{
		auto curr = levelQueue.front();
		levelQueue.pop();

		if (curr == nullptr)
		{
			level++;
			if (!levelQueue.empty())
				levelQueue.push(nullptr);

			continue;
		}

		if (curr->left != nullptr)
			levelQueue.push(curr->left);

		if (curr->right != nullptr)
			levelQueue.push(curr->right);

		cout << "level : " << level << " node: " << curr->value << endl;
	}

}


void BTree::displayList()
{
	auto curr = m_root;
	while (curr)
	{
		cout << "node :" << curr->value << endl;
		curr = curr->left;
	}



}
void BTree::displayTree()
{
	cout << "pre Order print " << endl;
	_preOrder(m_root);
	cout << "level by level print " << endl;
	levelPrint();

}

int BTree::_calcWidth(Node *root, int distance)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return distance;

	return (abs(_calcWidth(root->left, distance + 1)) + abs (_calcWidth(root->right, distance - 1))); 
}

int BTree::calcWidth()
{
	return _calcWidth(m_root, 0) + 1;
}

void BTree::convertToList()
{
	if (m_root == nullptr)
		return;

	queue<Node *> levelQueue;
	levelQueue.push(m_root);

	while(!levelQueue.empty())
	{
		auto curr = levelQueue.front();
		levelQueue.pop();

	
		if (curr->left != nullptr)
			levelQueue.push(curr->left);

		if (curr->right != nullptr)
			levelQueue.push(curr->right);

		if (levelQueue.empty())
			curr->left = nullptr;
		else
			curr->left = levelQueue.front();

		curr->right = nullptr;

	}

}


int main()
{

	std::unique_ptr<BTree> t1(new BTree);
	auto t2 = std::make_shared<BTree> ();
	//vector <int> items {5,6,8,2,7,9,3, 70, 1, 15, 12, 4};
	//vector <int> items { 4, 3, 5, 6, 1, 2};
	vector <int> items { 9,8,7,6,5,4,3,2,1,0};

	for (auto &x : items)
		t1->addNode(x);

	cout << "width of the tree is " << t1->calcWidth();

//	t1->displayTree();
	t1->convertToList();

	cout << endl << "Tree after converting to list" << endl;

	t1->displayTree();


	return 0;

}
