#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};
*/
/* Approach
   We will solve this using a recursive approach
   1. We will traverse the tree from top to bottom and will have two
      condition for recursive calls
      - Base Case, root == NULL; return
      - If curr->data > v1 and curr->data > v2, then call the function
        recursively for the left subtree
      - If curr->data < v1 and curr->data < v2, then call the function
        recursively for the right subtree
      - If both the condition are not true, return the node
        This is out LCA
 */

  
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        // Base Case
        if(root == NULL) return NULL;
        
        // If the curr data is smaller than both the given values
        if (root->data > v1 && root->data > v2)
            return lca(root->left, v1, v2);
        // If the curr data is greater than both the given values
        if(root->data < v1 && root->data < v2)
            return lca(root->right, v1, v2);
        
        return root;
    }

}; //End of Solution