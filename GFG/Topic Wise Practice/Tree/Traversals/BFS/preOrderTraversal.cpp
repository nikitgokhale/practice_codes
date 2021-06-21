/* C++ code for Breadth First Traversal(BFS) 
   2. PreOrder Traversal*/
#include <stdc++.h>

using namespace std;
using std::vector;

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
	void priv_PreOrder(Node* root, vector<int>& preOrder_vect);

public:
	binaryTree();
	~binaryTree();

	void destroyTree();
	void insert(int item);
	void preOrder(vector<int>& preOrder_vect);

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

void binaryTree::preOrder(vector<int>& preOrder_vect) {
	priv_PreOrder(root, preOrder_vect);
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

void binaryTree::priv_PreOrder(Node* root, vector<int>& preOrder_vect)
{
	if (root) {
		preOrder_vect.push_back(root->data);
		priv_PreOrder(root->left, preOrder_vect);
		priv_PreOrder(root->right, preOrder_vect);
	}
}

int main()
{
	binaryTree *bTree = new binaryTree();
	vector<int> preOrder_vect;
	
	bTree->insert(23);
	bTree->insert(12);
	bTree->insert(15);
	bTree->insert(5);
	bTree->insert(7);
	bTree->insert(31);
	bTree->insert(29);
	bTree->insert(88);
	bTree->insert(53);
	cout << "PreOrder is: ";
	bTree->preOrder(preOrder_vect);

	for (int i = 0; i < preOrder_vect.size(); i++)
	{
		cout << preOrder_vect[i] << " ";
	}
	cout << endl;
	
	return 0;

	return 0;
}