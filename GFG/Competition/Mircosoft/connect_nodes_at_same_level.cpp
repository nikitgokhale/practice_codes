
/* struct Node {
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};*/
/* Using Level Order Traversal to connect the next right nodes */
// The task is to connect the nodes level by level using the *nextRight pointer
// which will point to the nodes at the same level and if the node is the rightmost node
// in that level, then it will point to NULL
/*  
       10                      10 ------> NULL
      / \                     /   \
     3   5       =>         3 ------> 5 --------> NULL
    / \   \               /  \         \
   4   1   2            4 --> 1 -----> 2 -------> NULL

Approach:
1 Use level order traversal
2 Use the *nextRight pointer to point to the next nodes in the queue, until the size is not empty
3 Once the iteration of queue entry is finished, then make the node point to the NULL using 
  *nextRight pointer
*/


class Solution{
    public:
    void connect(Node *root)
    {
        // Code Here
        queue<Node*> q;
        q.push(root);
        
        Node* tmp = NULL;
        
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                Node* prev = tmp;
                tmp = q.front();
                q.pop();
                
                if (i > 0)
                    prev->nextRight = tmp;
                    
                if (tmp->left != NULL)
                    q.push(tmp->left);
                if (tmp->right != NULL)
                    q.push(tmp->right);
            }
            tmp->nextRight = NULL;
        }
    }    
};

