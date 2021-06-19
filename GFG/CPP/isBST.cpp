
class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    void isBSTUtil(Node* root, vector<int>& res)
    {
        if (root == NULL)
            return;
        isBSTUtil(root->left, res);
        res.push_back(root->data);
        isBSTUtil(root->right, res);
    }
    
    bool isBST(Node* root) 
    {
        // Your code here
        vector<int> res;
        res.clear();
        isBSTUtil(root, res);
        
        for(int i = 1; i < res.size(); i++){
            if (res[i] <= res[i-1])
                return false;
        }
        return true;
    }
};