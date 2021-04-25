/*
 * Author: Nikit Gokhale
 * Date: 04-03-2021
 *
 * This is a code which contains all the operation we can perform on a basic Binary Search Tree.
 * It mainly is my practice code, which I coded during solving most of the questions
 * from geeksforgeeks.org.
 * Hope you find it helpful
 */

/* INCLUDES */
#include<stdc++.h>

/* USINGS */
using std::vector;
using std::map;
using std::queue;
using std::stack;
using std::pair;

/* TYPEDEFS and STRUCTS */
struct Node
{
	int key_value;
	Node* lchild;
	Node* rchild;
	/* Constuctor */
	Node(int x) {
		key_value = x;
		lchild = NULL;
		rchild = NULL;
	}
};

struct listNode
{
	int data;
	listNode* next;
	/* Constructor */
	listNode(int x) {
		data = x;
		next = NULL;
	}
};

/* DEFINES */
#define MAX 20

/* CLASS */
class binaryTree
{
public:
	/* These are the user accessible methods to be used with trees */
	/* FUNCTION DECLARATION */
	binaryTree();
	~binaryTree();

	void insert(int item);
	void destroyTree();
	void PreOrder(vector<int>& vpr);
	void InOrder(vector<int>& vin);
	void PostOrder(vector<int> &vpo);
	void LevelOrder(vector<int>& vle);
	void LevelOrder_lvl();
	bool search(int key);
	int	 FindMin();
	int	 FindMax();
	int	 InOrderSuccessor(int key);
	int	 InOrderPredecessor(int key);
	int	 height_BST();
	void bottomView();
	void delete_nrec(int dkey);


	/* PUBLIC CLASS FUNCTION */
	Node* GetNewNode(int data)
	{
		Node* newNode = new Node(data);
		return newNode;
	}

private:
	void		priv_destroyTree(Node* leaf);
	void		priv_insert(int data, Node* leaf);
	Node*		priv_search(int key, Node* leaf);
	void		priv_PreOrder(Node* leaf, vector<int>& vpr);
	void		priv_InOrder(Node* leaf, vector<int>& vin);
	void		priv_PostOrder(Node* leaf, vector<int> &vpo);
	void		priv_LevelOrder(Node* leaf, vector<int>& vle);
	void		priv_LevelOrder_lvl(Node* leaf);
	Node*		priv_search_NREC(Node* leaf, int key);
	Node*		priv_search(Node* leaf, int key);
	int			priv_FindMin(Node* leaf);
	int			priv_FindMax(Node* leaf);
	int			priv_InOrderSuccessor(Node* keyNode);
	int			priv_InOrderPredecessor(Node* keyNode);
	int			priv_height_BST(Node* leaf);
	vector<int> priv_bottomView(Node* leaf);
	Node*		priv_constructBT(listNode* inPtr, listNode* prePtr, int num);
	Node*		priv_delete_nrec(Node* leaf, int dkey);

	Node* root;
};

/* Stack Class is used wherver we are not following a recursive approach to
 * solve the problem/questions.
 */
class Stack
{
private:
	Node* stack[MAX];
	int top = -1;

public:
	void push_stack(Node* item)
	{
		if (top == MAX - 1) {
			std::cout << "Stack Overflow!" << std::endl;
			return;
		}
		top += 1;
		stack[top] = item;
	}

	Node* pop_stack()
	{
		Node* tmp = new Node(NULL);
		if (isEmpty()) {
			std::cout << "Stack Underflow!" << std::endl;
			return 0;
		}
		tmp = stack[top];
		top -= 1;
		return tmp;
	}

	int isEmpty()
	{
		if (top == -1)
			return 1;
		else
			return 0;
	}
};

/* Queue Class is used wherver we are not following a recursive approach to
 * solve the problem/questions.
 */
class Queue
{
private:
	Node* queue[MAX];
	int front = -1;
	int rear = -1;
public:
	void insert_queue(Node* item)
	{
		if (rear == MAX - 1) {
			std::cout << "Queue Overflow!" << std::endl;
			return;
		}
		if (front == -1)
			front = 0;
		rear += 1;
		queue[rear] = item;
	}

	Node* delete_queue()
	{
		Node* item = new Node(NULL);
		if (isEmpty()) {
			std::cout << "Queue Underflow!" << std::endl;
			return 0;
		}
		item = queue[front];
		front += 1;
		return item;
	}

	int isEmpty()
	{
		if (front == -1 || front == rear + 1)
			return 1;
		else
			return 0;
	}
};

/* PUBLIC FUNCTION DEFINITIONS */
binaryTree::binaryTree()
{
	root = NULL;
}

binaryTree::~binaryTree()
{
	destroyTree();
}

int binaryTree::FindMin()
{
	return priv_FindMin(root);
}

int binaryTree::FindMax()
{
	return priv_FindMax(root);
}

void binaryTree::destroyTree()
{
	priv_destroyTree(root);
}

void binaryTree::insert(int data)
{
	if (root != NULL)
		priv_insert(data, root);
	else {
		root = GetNewNode(data);
	}
}

void binaryTree::delete_nrec(int dkey)
{
	root = priv_delete_nrec(root, dkey);
}

void binaryTree::PreOrder(vector<int>& vpr)
{
	priv_PreOrder(root, vpr);
	std::cout << "\n";
}

void binaryTree::InOrder(vector<int>& vin)
{
	priv_InOrder(root, vin);
	std::cout << "\n";
}

void binaryTree::PostOrder(vector<int> &vpo)
{
	priv_PostOrder(root, vpo);
	std::cout << "\n";
}

void binaryTree::LevelOrder(vector<int>& vle)
{
	priv_LevelOrder(root, vle);
	std::cout << "\n";
}

void binaryTree::LevelOrder_lvl()
{
	std::cout << "The Level Order Traversal (Level by Level) is: " << std::endl;
	priv_LevelOrder_lvl(root);
	std::cout << "\n";
}

bool binaryTree::search(int key)
{
	Node* result = priv_search_NREC(root, key);
	//Node* result = priv_search(root, key);
	/* If key is found, return TRUE else return FLASE */
	return result == NULL ?
		false :
		true;
}

int binaryTree::InOrderSuccessor(int key)
{
	// Search for the Key's node
	Node* keyNode = priv_search(root, key);
	// If the key is not found or if the successor is not found.
	// Return -1
	return keyNode == NULL ?
		-1 :
		priv_InOrderSuccessor(keyNode);
}

int binaryTree::InOrderPredecessor(int key)
{
	// Search for the Key's node
	Node* keyNode = priv_search(root, key);
	// Pass this keyNode to the private Predecessor function
	// If key is not found or if the successor is not found
	// Return -1
	return keyNode == NULL ?
		-1 :
		priv_InOrderPredecessor(keyNode);
}

int binaryTree::height_BST()
{
	return priv_height_BST(root);
}

void binaryTree::bottomView()
{
	vector<int> an = priv_bottomView(root);
	for (auto i : an)
		std::cout << i << " ";
}


/* PRIVATE FUNCTION DEFINITIONS */
/* This function will delete all the nodes recursively */
void binaryTree::priv_destroyTree(Node* leaf)
{
	if (leaf != NULL) {
		priv_destroyTree(leaf->lchild);
		priv_destroyTree(leaf->rchild);
		delete leaf;
	}
}
/* This function */
void binaryTree::priv_insert(int data, Node* leaf)
{
	if (data < leaf->key_value) {
		if (leaf->lchild != NULL)
			priv_insert(data, leaf->lchild);
		else {
			leaf->lchild = GetNewNode(data);
		}
	}
	else if (data >= leaf->key_value){
		if (leaf->rchild != NULL)
			priv_insert(data, leaf->rchild);
		else {
			leaf->rchild = GetNewNode(data);
		}
	}
}

Node* binaryTree::priv_delete_nrec(Node* leaf, int dkey)
{
	Node* ptr;
	Node* par;
	Node* succ;
	Node* parSucc;
	Node* child;
	ptr = leaf;
	par = NULL;
	while (ptr != NULL){
		if (dkey == ptr->key_value)
			break;
		par = ptr;
		if (dkey < ptr->key_value)
			ptr = ptr->lchild;
		else
			ptr = ptr->rchild;
	}
	if (ptr == NULL){
		std::cout << "The delete key is not present in the Tree" << std::endl;
		return root;
	}
	/* Case C: Where Node has both right and left child */
	/* Find the inorder successor and interchange the data with the delete node's data */
	if (ptr->lchild != NULL && ptr->rchild != NULL){ /* Has both the child */
		parSucc = ptr;
		succ = ptr->rchild;
		while (succ->lchild != NULL){
			parSucc = succ;
			succ = succ->lchild;
		}
		ptr->key_value = succ->key_value;
		ptr = succ;
		par = parSucc;
	}
	/* Case A or Case B */
	/* Case where the Node has no child or 1 child */
	if (ptr->lchild != NULL)  	/* node to be deleted has left child */
		child = ptr->lchild;
	else						/* Node to be deleted has right child */
		child = ptr->rchild;

	if (par == NULL)			/* node to be deleted is the root node */
		root = child;
	/* Conditions to assign the child of the node to be deleted to the parent */
	else if (ptr == par->lchild) /* node is the left child of its parent */
		par->lchild = child;
	else						/* Node is the right child of its parent */
		par->rchild = child;
	free(ptr);
	return root;
}

Node* binaryTree::priv_search(int data, Node* leaf)
{
	if (leaf != NULL) {
		if (data == leaf->key_value)
			return leaf;
		if (data < leaf->key_value)
			return priv_search(data, leaf->lchild);
		else
			return priv_search(data, leaf->rchild);
	}
	else
		return NULL;
}

void binaryTree::priv_PreOrder(Node* leaf, vector<int>& vpr)
{
	if (leaf) {
		//std::cout << leaf->key_value << " ";
		vpr.push_back(leaf->key_value);
		priv_PreOrder(leaf->lchild, vpr);
		priv_PreOrder(leaf->rchild, vpr);
	}
}


void binaryTree::priv_InOrder(Node* leaf, vector<int>& vin)
{
	if (leaf) {
		priv_InOrder(leaf->lchild, vin);
		//std::cout << leaf->key_value << " ";
		vin.push_back(leaf->key_value);
		priv_InOrder(leaf->rchild, vin);
	}
}

void binaryTree::priv_PostOrder(Node* leaf, vector<int> &vpo)
{
	if (leaf) {
		priv_PostOrder(leaf->lchild, vpo);
		priv_PostOrder(leaf->rchild, vpo);
		vpo.push_back(leaf->key_value);
		//std::cout << leaf->key_value << " ";
	}
}

void binaryTree::priv_LevelOrder(Node* leaf, vector<int>& vle)
{
	Queue *tmp = new Queue();
	Node* ptr = new Node(*leaf);
	if (ptr == NULL) {
		std::cout << "Tree is Empty!" << std::endl;
		return;
	}
	tmp->insert_queue(ptr);
	while (!tmp->isEmpty()) {
		ptr = tmp->delete_queue();
		vle.push_back(ptr->key_value);
		//std::cout << ptr->key_value << " ";
		if (ptr->lchild != NULL)
			tmp->insert_queue(ptr->lchild);
		if (ptr->rchild != NULL)
			tmp->insert_queue(ptr->rchild);
	}
}

void binaryTree::priv_LevelOrder_lvl(Node* leaf)
{
	queue<Node*> q;
	Node* ptr = new Node(0);
	if (ptr == NULL) {
		std::cout << "Tree is Empty!" << std::endl;
		return;
	}
	q.push(leaf);
	q.push(NULL);
	while (q.size() > 1) {
		ptr = q.front();
		q.pop();
		if (ptr == NULL) {
			q.push(NULL);
			std::cout << "\n";
		}
		else {
			std::cout << ptr->key_value << " ";
			if (ptr->lchild != NULL)
				q.push(ptr->lchild);
			if (ptr->rchild != NULL)
				q.push(ptr->rchild);
		}
	}
}

Node* binaryTree::priv_search_NREC(Node* leaf, int key)
{
	while (leaf) {
		if (key < leaf->key_value)
			leaf = leaf->lchild; /* Move to the left child*/
		else if (key > leaf->key_value)
			leaf = leaf->rchild;
		else
			return leaf;
	}
	std::cout << "Key not found!!" << std::endl;
	return NULL;
}

Node* binaryTree::priv_search(Node* leaf, int key)
{
	if (leaf) {
		if (key < leaf->key_value)
			return priv_search(leaf->lchild, key);
		else if (key > leaf->key_value)
			return priv_search(leaf->rchild, key);
		else
			return leaf;
	}
	else {
		std::cout << "Key not found!!\n" << std::endl;
		return NULL;
	}
}

int binaryTree::priv_FindMin(Node* leaf)
{
	if (leaf == NULL) {
		std::cout << "Tree is Empty!!" << std::endl;
		return NULL;
	}
	else if (leaf->lchild == NULL) {
		return leaf->key_value;
	}
	else
		return priv_FindMin(leaf->lchild);
}

int binaryTree::priv_FindMax(Node* leaf)
{
	if (leaf == NULL) {
		std::cout << "Tree is Empty!" << std::endl;
		return NULL;
	}
	else if (leaf->rchild == NULL)
		return leaf->key_value;
	else
		return priv_FindMax(leaf->rchild);
}

int binaryTree::priv_InOrderSuccessor(Node* keyNode)
{
	if (keyNode->rchild != NULL)
		return priv_FindMin(keyNode->rchild);

	Node* succ = new Node(NULL);

	// Start from the root searching the successor down the tree
	while (root != NULL) {
		if (keyNode->key_value < root->key_value) {
			succ = root;
			root = root->lchild;
		}
		else if (keyNode->key_value > root->key_value) {
			root = root->rchild;
		}
		else
			break;
	}
	return succ->key_value;
}

int binaryTree::priv_InOrderPredecessor(Node* keyNode)
{
	if (keyNode->lchild != NULL)
		return priv_FindMax(keyNode->lchild);

	Node* pred = new Node(NULL);

	// Start from the root searching the successor down the tree
	while (root != NULL) {
		if (keyNode->key_value > root->key_value) {
			pred = root;
			root = root->rchild;
		}
		else if (keyNode->key_value < root->key_value)
			root = root->lchild;
		else
			break;
	}
	return pred->key_value;
}

int binaryTree::priv_height_BST(Node* leaf)
{
	int left_h = -1, right_h = -1;
	if (!leaf)	
		return 0;
	if (leaf->lchild) {
		left_h = priv_height_BST(leaf->lchild);
	}
	if (leaf->rchild) {
		right_h = priv_height_BST(leaf->rchild);
	}

	if (left_h > right_h)
		return left_h+1;
	else
		return right_h+1;
}

vector<int> binaryTree::priv_bottomView(Node* leaf)
{
	map<int, int> mp;
	queue < pair<Node*, int>> q;
	q.push({ leaf, 0 });
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		leaf = t.first;
		mp[t.second] = leaf->key_value;
		if (leaf->lchild)
			q.push({ leaf->lchild, t.second - 1 });
		if (leaf->rchild)
			q.push({ leaf->rchild, t.second + 1 });
	}

	vector<int>ans;
	for (auto i : mp)
		ans.push_back(i.second);
	return ans;
}

Node* binaryTree::priv_constructBT(listNode* inPtr, listNode* prePtr, int num)
{
	Node* tmp = GetNewNode(NULL);
	listNode* q = new listNode(NULL);
	static int i, j;
	if (num == 0)
		return NULL;
	tmp->key_value = prePtr->data;
	if (num == 1)
		return tmp;
	q = inPtr;
	for (i = 0; q->data != prePtr->data; i++)
		q = q->next;
	/* Now q points to the root node in the InOrder and the
	   number of nodes in the left subtree are i */
	tmp = priv_constructBT(inPtr, prePtr->next, i);

	/* Constructing the right subtree */
	for (j = 1; j <= i + 1; j++)
		prePtr = prePtr->next;

	tmp->rchild = priv_constructBT(q->next, prePtr, num - i - 1);
	return tmp;
}

/* GLOBAL FUNCTION DEFINTIONS */
int main()
{
	binaryTree *tree = new binaryTree();

	vector<int> vect_inOrder;
	vector<int> vect_preOrder;
	vector<int> vect_postOrder;
	vector<int> vect_levelOrder;
	vector<int> vect_treeWithInAndPost;
	vector<int> inOrderAfterDel;

	tree->insert(23);
	tree->insert(12);
	tree->insert(15);
	tree->insert(5);
	tree->insert(7);
	tree->insert(31);
	tree->insert(29);
	tree->insert(88);
	tree->insert(53);
	std::cout << "The PreOrder is: ";
	tree->PreOrder(vect_preOrder);
	for (int pre : vect_preOrder) {
		std::cout << pre << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "The InOrder is: ";
	tree->InOrder(vect_inOrder);
	for (int in : vect_inOrder) {
		std::cout << in << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "The PostOrder is: ";
	tree->PostOrder(vect_postOrder);
	for (int po : vect_postOrder) {
		std::cout << po << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "The LevelOrder is: ";
	tree->LevelOrder(vect_levelOrder);
	for (int le : vect_levelOrder) {
		std::cout << le << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	tree->LevelOrder_lvl();
	std::cout << std::endl;
	//std::cout << tree->search(20) << std::endl;
	int max = tree->FindMax();
	int min = tree->FindMin();
	std::cout << "Min value in the tree: " << min << std::endl;
	std::cout << "Max value in the tree: " << max << std::endl;
	int succ = tree->InOrderSuccessor(31);
	std::cout << "The InOrder Successor of 31 is " << succ << std::endl;
	int pred = tree->InOrderPredecessor(12);
	std::cout << "The InOrder Predecessor of 12 is " << pred << std::endl;
	int height = tree->height_BST();
	std::cout << "Height of the BST is: " << height << std::endl;
	std::cout << "BottomView of the BST is: ";
	tree->bottomView();
	std::cout << std::endl;
	//std::cout << "Constructing a BST using InOrder and PreOrder Traversal: " << std::endl;
	////listNode* inPtr = vect_inOrder;
	//std::cout << "The BST is: ";
	tree->delete_nrec(31);
	std::cout << "The InOrder is: ";
	tree->InOrder(inOrderAfterDel);
	for (int in : inOrderAfterDel) {
		std::cout << in << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}