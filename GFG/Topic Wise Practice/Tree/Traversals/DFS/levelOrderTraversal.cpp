/* C++ code for Deapth First Traversal(BFS) 
   1. Level Order Traversal */
#include <bits/stdc++.h>

using namespace std;
using std::vector;
using std::stack;
using std::queue;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

class binaryTree
{
private:
	Node* root;
	void priv_destroy(Node* root);
	void priv_insert(Node* root, int item);
	void priv_LevelOrder(Node* root, vector<int>& postOrder_vect);

public:
	binaryTree();
	~binaryTree();

	void destroyTree();
	void insert(int item);
	void levelOrder(vector<int>& postOrder_vect);

	Node* getNewNode(int data)
	{
		Node* newNode = new Node(data);
		return newNode;
	}
};

binaryTree::binaryTree()
{
	root = NULL;
}

binaryTree::~binaryTree()
{
	destroyTree();
}

void binaryTree::destroyTree()
{
	priv_destroy(root);
}

void binaryTree::insert(int item)
{
	if (root != NULL)
		priv_insert(root, item);
	else
		root = getNewNode(item);
}

void binaryTree::levelOrder(vector<int>& postOrder_vect) {
	priv_LevelOrder(root, postOrder_vect);
}


void binaryTree::priv_destroy(Node* root)
{
	if (root != NULL) {
		priv_destroy(root->left);
		priv_destroy(root->right);
		delete root;
	}
}

void binaryTree::priv_insert(Node* root, int item)
{
	if (item < root->data) {
		if (root->left != NULL) {
			priv_insert(root->left, item);
		}
		else {
			root->left = getNewNode(item);
		}
	}
	if (item > root->data) {
		if (root->right != NULL)
			priv_insert(root->right, item);
		else
			root->right = getNewNode(item);
	}
}

void binaryTree::priv_LevelOrder(Node* root, vector<int>& levelOrder_vect)
{
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* tmp = q.front();
		q.pop();
		levelOrder_vect.push_back(tmp->data);
		if(tmp->left != NULL)
			q.push(tmp->left);
		if(tmp->right != NULL)
			q.push(tmp->right);
	}
}

int main()
{
	binaryTree *bTree = new binaryTree();
	vector<int> levelOrder_vect;
	
	bTree->insert(23);
	bTree->insert(12);
	bTree->insert(15);
	bTree->insert(5);
	bTree->insert(7);
	bTree->insert(31);
	bTree->insert(29);
	bTree->insert(88);
	bTree->insert(53);
	cout << "Level Order is: ";
	bTree->levelOrder(levelOrder_vect);

	for (int i = 0; i < levelOrder_vect.size(); i++)
	{
		cout << levelOrder_vect[i] << " ";
	}
	cout << endl;
	
	return 0;

	return 0;
}