/* C++ code for Breadth First Traversal(BFS) 
   3. PostOrder Traversal*/
#include <bits/stdc++.h>

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
	void priv_PostOrder(Node* root, vector<int>& postOrder_vect);

public:
	binaryTree();
	~binaryTree();

	void destroyTree();
	void insert(int item);
	void postOrder(vector<int>& postOrder_vect);

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

void binaryTree::postOrder(vector<int>& postOrder_vect) {
	priv_PostOrder(root, postOrder_vect);
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

void binaryTree::priv_PostOrder(Node* root, vector<int>& postOrder_vect)
{
	if (root) {
		priv_PostOrder(root->left, postOrder_vect);
		priv_PostOrder(root->right, postOrder_vect);
		postOrder_vect.push_back(root->data); 
	}
}

int main()
{
	binaryTree *bTree = new binaryTree();
	vector<int> postOrder_vect;
	
	bTree->insert(23);
	bTree->insert(12);
	bTree->insert(15);
	bTree->insert(5);
	bTree->insert(7);
	bTree->insert(31);
	bTree->insert(29);
	bTree->insert(88);
	bTree->insert(53);
	cout << "PostOrder is: ";
	bTree->postOrder(postOrder_vect);

	for (int i = 0; i < postOrder_vect.size(); i++)
	{
		cout << postOrder_vect[i] << " ";
	}
	cout << endl;
	
	return 0;

	return 0;
}