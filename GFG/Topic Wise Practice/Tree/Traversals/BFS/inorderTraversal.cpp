/* C++ code for Breadth First Traversal(BFS) 
   1. Inorder Traversal*/
#include <stdc++.h>

using namespace std;
using std::vector;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};


class binaryTree
{
private:
	Node* root;
	void priv_insert(Node* root, int item);
	void priv_destroy(Node* root);
	void priv_inOrder(Node* root, vector<int>& inOrder_vect);

public:
	binaryTree();
	~binaryTree();

	void destroyTree();
	void insert(int data);
	void inOrder(vector<int>& inOrder_vect);

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
	// Base condition, when there's no Root Node
	if(root != NULL)
		priv_insert(root, item);
	else
		root = getNewNode(item);
}

void binaryTree::inOrder(vector<int>& inOrder_vect)
{
	priv_inOrder(root, inOrder_vect);
	cout << endl;
}

void binaryTree::priv_destroy(Node* root)
{
	if(root != NULL){
		priv_destroy(root->left);
		priv_destroy(root->right);
		delete root;
	}
}

void binaryTree::priv_inOrder(Node* root, vector<int>& inOrder_vect)
{
	if (root)
	{
		priv_inOrder(root->left, inOrder_vect);
		inOrder_vect.push_back(root->data);
		priv_inOrder(root->right, inOrder_vect);
	}
}

void binaryTree::priv_insert(Node* root, int item)
{
	// Here we'll check if the Node to be inserted is having value less than the
	// the root node, if yes, move to the left subtree
	// If no, move to the right subtree.
	// Do this until we find the perfect spot for 'item'
	if (item < root->data) {
		if (root->left != NULL)
			priv_insert(root->left, item);
		else
			root->left = getNewNode(item);
	}
	if (item > root->data) {
		if (root->right != NULL)
			priv_insert(root->right, item);
		else
			root->right = getNewNode(item);
	}

}

int main()
{
	binaryTree *bTree = new binaryTree();
	vector<int> inOrder_vect;
	

	bTree->insert(23);
	bTree->insert(12);
	bTree->insert(15);
	bTree->insert(5);
	bTree->insert(7);
	bTree->insert(31);
	bTree->insert(29);
	bTree->insert(88);
	bTree->insert(53);
	cout << "InOrder is: ";
	bTree->inOrder(inOrder_vect);

	for (int i = 0; i < inOrder_vect.size(); i++)
	{
		cout << inOrder_vect[i] << " ";
	}
	cout << endl;
	
	return 0;
}