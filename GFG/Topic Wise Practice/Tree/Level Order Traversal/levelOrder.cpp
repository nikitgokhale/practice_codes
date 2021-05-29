struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        //Your code here
        vector<int> res;
        if (node == NULL)
            return res;
        
        queue<Node*> q;
        q.push(node);
        while (!q.empty()){
            Node* tmp = q.front();
            res.push_back(tmp->data);
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
        return res;
    }
};