
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

// Return the level (0-indexed) with maximum number of nodes.
int maxNodeLevel(Node *root)
{
    // Add your code here
    if (root == NULL)
        return -1;
        
    queue<Node*> q;
    q.push(root);
    
    int level = 0;
    int max = INT_MIN;
    int level_no = 0;
    
    while (1){
        int NodeCount = q.size();
        if (NodeCount == 0)
            break;
            
        if (NodeCount > max){
            max = NodeCount;
            level_no = level;
        }
        
        while (NodeCount > 0){
            Node* tmp = q.front();
            q.pop();
            if (tmp->left != NULL)
                q.push(tmp->left);
            if (tmp->right != NULL)
                q.push(tmp->right);
            NodeCount--;
        }
        level++;
    }
    return level_no;
}