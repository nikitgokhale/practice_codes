/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified tree after removing all the half nodes.
Node *RemoveHalfNodes(Node *root)
{
    //add code here.
    if (!root)
        return root;
    // Post Order Traversing, for bottom-up approach 
    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    // If the current parent has only left child
    if (root->left && !root->right)
        return root->left;
    // If the current parent has only right child.        
    if (root->right && !root->left)
        return root->right;
        
    return root;
    
}