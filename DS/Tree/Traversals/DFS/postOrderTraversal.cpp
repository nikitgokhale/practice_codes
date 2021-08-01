/* C++ code for Breadth First Traversal(BFS) 
   3. PostOrder Traversal*/
#include <bits\stdc++.h>

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
	void priv_PostOrderItr(Node* root, vector<int>& postOrder_vect);

public:
	binaryTree();
	~binaryTree();

	void destroyTree();
	void insert(int item);
	void postOrder(vector<int>& postOrder_vect);
	void postOrderItr(vector<int>& postOrder_vect);

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

void binaryTree::postOrderItr(vector<int>& postOrder_vect) {
	priv_PostOrderItr(root, postOrder_vect);
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

void binaryTree::priv_PostOrderItr(Node* root, vector<int>& postOrder_vect) {
	// Base Case: if the tree is empty, return
	if (!root) {
		return;
	}

	// Create an empty stack and push the root node
	stack<Node*> __stack;
	__stack.push(root);
	// Create an out stack which displays the postOrder traversal
	stack<int> out;
	// Iterate till the stack is empty
	while (!__stack.empty()) {
		// Pop from the stack and push it into the output stack
		Node* tmp = __stack.top();
		__stack.pop();

		out.push(tmp->data);
		// Push the left and the right child of the popped node into the stack
		if (tmp->left != NULL) {
			__stack.push(tmp->left);
		}
		if (tmp->right != NULL) {
			__stack.push(tmp->right);
		}
	}
	// Push the postOrder traversal into the resultant vector
	while (!out.empty()) {
		postOrder_vect.push_back(out.top());
		out.pop();
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
	// bTree->postOrder(postOrder_vect);
	bTree->postOrderItr(postOrder_vect);

	for (int i = 0; i < postOrder_vect.size(); i++)
	{
		cout << postOrder_vect[i] << " ";
	}
	cout << endl;
	
	return 0;

	return 0;
}