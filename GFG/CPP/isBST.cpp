/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/
/* Approach:
    Using a vector to determine if the given binary tree is BST 
    In Inorder Traversal, the nodes are printed as left->root->right.
    So with this way, if the given binary tree is a BST, then the inorder traversal
    of a Binary Tree will be in ascending order.
    So push the node's data into the vector in Inorder way.
    Check the ascending order in the vector, if not followed, return false.
    */
    void checkBSTHelper(Node* root, vector<int>& res)
    {
        if(root == NULL)
            return;
        checkBSTHelper(root->left, res);
        res.push_back(root->data);
        checkBSTHelper(root->right, res);
    }
    
    bool checkBST(Node* root)
    {
        vector<int> res;
        res.clear();
        checkBSTHelper(root, res);
        
        for(int i=0; i<res.size(); i++) {
            if(res[i] <= res[i-1])
                return false;
        }
        return true;
    }