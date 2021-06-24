/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
Node* constructTreeUtil(int n, int pre[], char preLN[], int *ix_ptr)
{
    int ix = *ix_ptr;
    
    if (ix == n)
        return NULL;
        
    Node* root = new Node(pre[ix]);
    (*ix_ptr)++;
    
    if (preLN[ix] == 'N'){
        root->left = constructTreeUtil(n, pre, preLN, ix_ptr);
        root->right = constructTreeUtil(n, pre, preLN, ix_ptr);
    }
    return root;
}


struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int ix = 0;
    
    return constructTreeUtil(n, pre, preLN, &ix);
}