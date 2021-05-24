/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/*You are required to complete below method */
void treePathsSumUtil(Node* root, long long& res, long long curr)
{
    if (!root)
        return;
    if (root->left == NULL && root->right == NULL){
        curr = curr*10 + root->data;
        res += curr;
        return;
    }
    treePathsSumUtil(root->left, res, (curr*10)+root->data);
    treePathsSumUtil(root->right, res, (curr*10)+root->data);
}

long long treePathsSum(Node *root)
{
    //Your code here
    long long res = 0;
    treePathsSumUtil(root, res, 0);
    return res;
}