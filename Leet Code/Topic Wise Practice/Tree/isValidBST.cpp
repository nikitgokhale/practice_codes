/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /* This is an effecient approach to the above InOrder Traversal algorithm 
       Here we use the prev ptr to take a note of the visited nodes,
       if the value of the current node is greater than the previous node,
       then it is not a BST.
       Using this method we also avoid using an auxillary array/vector which
       stores the Node's data and we also avoid extra comparison to check that
       the elements in the array are following the ascending order.
    */

    void inValidBSTUtil(TreeNode* root, TreeNode*& prev, bool &isValid) {
        if (root != NULL) {
            inValidBSTUtil(root->left, prev, isValid);
            if (prev != NULL && prev->val >= root->val) {
                isValid = false;
                return;
            }
            
            prev = root;
            inValidBSTUtil(root->right, prev, isValid);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        bool isValid = true;
        inValidBSTUtil(root, prev, isValid);
        
        return isValid;
    }
};