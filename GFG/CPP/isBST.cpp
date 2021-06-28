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

    /* This is an effecient approach to the above InOrder Traversal algorithm 
       Here we use the prev ptr to take a note of the visited nodes,
       if the value of the current node is greater than the previous node,
       then it is not a BST.
       Using this method we also avoid using an auxillary array/vector which
       stores the Node's data and we also avoid extra comparison to check that
       the elements in the array are following the ascending order.
    */
    void isValidBST(Node* root, Node*& prev, bool& isValid) {
        if (root != NULL) {
            isValidBST(root->left, prev, isValid);

            if (prev != NULL && prev->data >= root->data) {
                isValid = false;
                return;
            }

            prev = root;
            isValidBST(root->right, prev, isValid);
        }
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

    bool isValidBST(Node* root) {
        bool isValid = true;
        Node* prev = NULL;

        isValidBSTUtil(root, prev, isValid);

        return isValid;
    }