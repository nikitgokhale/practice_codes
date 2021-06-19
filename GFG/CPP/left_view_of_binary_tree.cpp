/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
void leftViewUtil(Node *root, vector<int>& res)
{
    // Your code here
    if(!root)
        return;
        
    queue<Node*> q;
    
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            Node* tmp = q.front();
            q.pop();
            
            if (i == 0){
                res.push_back(tmp->data);
            }
            
            if (tmp->left != NULL){
                q.push(tmp->left);
            }
            if (tmp->right != NULL){
                q.push(tmp->right);
            }
        }
    }
}

vector<int> leftView(Node *root)
{
    vector<int> res;
    leftViewUtil(root, res);
    return res;
}