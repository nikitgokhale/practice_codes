
/* INCLUDES */
#include<stdc++.h>

/* USINGS*/
using namespace std;

/* DEFINES */
#define TRUE 1
#define FALSE 0

/*TYPEDEFS AND STRUCTS*/
struct Node
{
	int key_value;
	Node* left;
	Node* right;
	int balance;
	/* Constructor of the class */
	Node(int x)
	{
		key_value = x;
		left = NULL;
		right = NULL;
		balance = 0;
	}
}*root; /* Entry point to the tree. */

/* CLASSES */
class balancedAVL
{
public:
	/* These are the user accessible methods to be used with trees */
	/* FUNCTION DECLARATION */
	balancedAVL();
	~balancedAVL();

	static int taller;

	void  destroyTree(Node* pptr);
	void  InOrderPrint(Node* pptr, vector<int>& vin);
	Node* insert(int item, Node* pptr);
	Node* insert_left_check(Node* pptr, int& taller);
	Node* insert_right_check(Node* pptr, int& taller);
	Node* insert_LeftBalance(Node* pptr);
	Node* insert_RightBalance(Node* pptr);
	Node* RotateLeft(Node* pptr);
	Node* RotateRight(Node* pptr);
	int   findHeight(Node* pptr);
	int   balancedFactor(Node* pptr);

	Node* root;
};

/* This tells us if we have to check for the balancing condirion or not
 * When set to TRUE, we have to check for the balancing condtion
 * If FALSE, then skip the check
 */
int balancedAVL::taller;
/* FUNCTION DEFINITIONS */
/* PUBLIC FUNCTION DEFINITIONS */
balancedAVL::balancedAVL()
{
	root = NULL;
}

balancedAVL::~balancedAVL()
{
	destroyTree(root);
}

/* FUNCTION DEFINITIONS */
int balancedAVL::findHeight(Node* pptr)
{
	int h = 0;
	if (pptr != NULL) {
		int leftH = findHeight(pptr->left);
		int rightH = findHeight(pptr->right);
		int maxHeight = max(leftH, rightH);
		h = maxHeight + 1;
	}
	return h;
}

/* To check the Balance Factor of the Tree */
/* Can be used to check for any node, just pass the address of the node when calling the function */
int balancedAVL::balancedFactor(Node* pptr)
{
	int left_h = findHeight(pptr->left);
	int right_h = findHeight(pptr->right);
	int bFactor = left_h - right_h;
	return bFactor;
}

void balancedAVL::destroyTree(Node* leaf)
{
	if (leaf != NULL) {
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}

Node* balancedAVL::RotateLeft(Node* pptr)
{
	Node* aptr;
	aptr = pptr->right;
	pptr->right = aptr->left;
	aptr->left = pptr;
	return aptr;
}

Node* balancedAVL::RotateRight(Node* pptr)
{
	Node* aptr;
	aptr = pptr->left;
	pptr->left = aptr->right;
	aptr->right = pptr;
	return aptr;
}

/* Insertion in a AVL tree */
Node* balancedAVL::insert(int item, Node* pptr)
{
	if (pptr == NULL) { /* Base Case */
		pptr = new Node(item);
		taller = TRUE;
		return pptr;
	}
	else if (item < pptr->key_value) { /* Insertion in Left Subtree */
		pptr->left = insert(item, pptr->left);
		if (taller == TRUE)  /* Check for the Balancing condition */
			pptr = insert_left_check(pptr, taller); /* Check for the balancing condtion in the left subtree */
	}
	else if (item > pptr->key_value) {  /* Insertion in Right Subtree */
		pptr->right = insert(item, pptr->right);
		if (taller == TRUE) /* Check for the Balancing condition */
			pptr = insert_right_check(pptr, taller);  /* Check for the balancing condtion in right subtree */
	}
	else {  /* Base Case */
		cout << "Duplicate key!!" << endl;
		taller = FALSE;
	}
	return pptr;
}

/* This Function checks for the balancing condition of the Subtree before insertion and updates the 
 * balancing condtion after insertion; for left subtree
 */
Node* balancedAVL::insert_left_check(Node* pptr, int& taller)
{
	switch (pptr->balance) {
	case 0: /* Was Balanced */
		pptr->balance = 1;  /* Not left heavy */
		break;
	case -1:  /* Was right heavy */
		pptr->balance = 0;  /* Now balanced */
		taller = FALSE;
		break;
	case 1:  /* Was left heavy */
		pptr = insert_LeftBalance(pptr);  /* Left Balancing required */
		taller = FALSE;
	}
	return pptr;
}

/* This function does some left balancing by rotating it the subtree around a node, left or right
 * as required
 */
Node* balancedAVL::insert_LeftBalance(Node* pptr)
{
	Node* aptr;  /*Left subtree of Pivot(root)*/
	Node* bptr;  /*Left or Right subtree of A */
	aptr = pptr->left;  /* Insetion in left subtree of A  */
	if (aptr->balance == 1) {
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else {  /* Insertion in Right Subtree A */
		bptr = aptr->right;
		switch (bptr->balance)
		{
		case -1:  /* Insertion in Right Subtree of B */
			pptr->balance = 0;
			aptr->balance = 1;
			break;
		case 1:  /* Insertion in Left Subtree of B*/
			pptr->balance = -1;
			aptr->balance = 0;
			break;
		case 0:  /* Inserting a new B */
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->left = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}

/* This Function checks for the balancing condition of the Subtree before insertion and updates the
 * balancing condtion after insertion; for Right subtree
 */
Node* balancedAVL::insert_right_check(Node* pptr, int& taller)
{
	switch (pptr->balance)
	{
	case 0:  /* Was Balanced */
		pptr->balance = -1;  /*Now right heavy */
		break;
	case 1:  /* Was Left Heavy */
		pptr->balance = 0;  /* Now Balanced */
		taller = FALSE;
		break;
	case -1: /* Was right heavy */
		pptr = insert_RightBalance(pptr);  /* Right Balancing Required */
		taller = FALSE;
	}
	return pptr;
}

/*  */
Node* balancedAVL::insert_RightBalance(Node* pptr)
{
	Node* aptr;
	aptr = pptr->right;
	if (aptr->balance == -1) {
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);
	}
	else {
		Node* bptr = aptr->left;
		switch (bptr->balance) {
		case -1:
			pptr->balance = 1;
			aptr->balance = 0;
			break;
		case 1:
			pptr->balance = 0;
			aptr->balance = -1;
			break;
		case 0:
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->right = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}

/* Adding the data members of the tree nodes in an InOrder way into the vector.
 * Recursive calling
*/
void balancedAVL::InOrderPrint(Node* pptr, vector<int>& vin)
{
	if (pptr) {
		InOrderPrint(pptr->left, vin);
		vin.push_back(pptr->key_value);
		InOrderPrint(pptr->right, vin);
	}
}

 /* GLOBAL MAIN FUNCTION */
int main()
{
	// Creating an object of the class "BalancedTree", to access all the public class methods
	balancedAVL* tree = new balancedAVL(); 
	
	/* For storing the data members of the tree nodes in an InOrder way*/
	vector<int> vect_inOrder;
	
	/* Inserting the data members as node in the tree */
	root = tree->insert(50, root);
	root = tree->insert(40, root);
	root = tree->insert(35, root);
	root = tree->insert(50, root);
	root = tree->insert(58, root);
	root = tree->insert(48, root);
	root = tree->insert(42, root);
	root = tree->insert(60, root);
	root = tree->insert(30, root);
	root = tree->insert(33, root);
	root = tree->insert(25, root);

	/* Printing the data members of the tree in InOrder Way */
	cout << "The InOrder is: ";
	tree->InOrderPrint(root, vect_inOrder);
	for (int in : vect_inOrder)
		cout << in << " ";
	cout << endl;
	 
	/*Height of the Tree */
	int height = tree->findHeight(root);
	cout << "Height of the Tree is: " << height << endl;;
	cout << endl;
	/* Balanced Factor of the Tree */
	int bf = tree->balancedFactor(root);
	cout << "Balanced Factor is: " << bf << endl;
	cout << endl;
	
	return 0;
}