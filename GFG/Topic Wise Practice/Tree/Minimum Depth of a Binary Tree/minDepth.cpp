/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution{
  public:
    /*You are required to complete this method*/
    int res = INT_MAX;
    
    void getAns(Node* root, int level)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL){
            if (level < res)
                res = level;
        }
        getAns(root->left, level+1);
        getAns(root->right, level+1);
    }
    
    int minDepth(Node *root) {
        // Your code here
        if (!root)
            return 0;
        getAns(root, 1);
        return res;
    }
};