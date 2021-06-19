/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

int height(Node* root){
    int leftH = -1, rightH = -1;
    if(root == NULL)
        return 0;
    if(root->left)
        leftH = height(root->left);
    if(root->right)
        rightH = height(root->right);

    if(leftH > rightH)
        return leftH+1;
    else
        return rightH+1;
}

/* Approach 1:
   'flag' is used to change printing order of levels. 
   If flag is true then pushGivenLevel() pushes the nodes from left to right in the vector
   else from right to left. 
   Value of flag is flipped in each iteration to change the order.
 */
//Function to return a list containing the level order traversal in spiral form.
void pushGivenLevel(Node* curr, int level, bool flag, vector<int>& res)
{
    if (root == NULL)
        return;
    if (level == 1)
        res.push_back(root->data);
    else if(level > 1){
        if(flag){
            pushGivenLevel(root->left, level-1, flag, res);
            pushGivenLevel(root->right, level-1, flag, res);
        }
        else{
            pushGivenLevel(root->right, level-1, flag, res);
            pushGivenLevel(root->left, level-1, flag, res);            
        }
    }
}

vector<int> __findSpiral(Node* root)
{
    // Your code
    vector<int> res;
    if(root == NULL)
        return res;

    int h = height(root);
    // flag -> Left to Right. If this variable
    // is set, then the given level is traversed 
    // from left to right
    // else vice versa
    bool flag = false;

    for(int i = 1; i <= h; i++){
        pushGivenLevel(root, i, flag, res);
        // Reverse the flag to traverse the next
        // level in reverse order
        flag = !flag;
    }
    return res;
}


/* Approach 2:
   Using two stack
   We can use one stack for pushing nodes in the vector from left to right
   and second stack for pushing nodes in the vector from right to left
   In every iteration,
   We'll have nodes from 1 level in one of the stack
   We print the nodes and push the nodes of next level in other stack 
*/
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> res;
    if(root == NULL)
        return res;
    bool flag = false;
    /* Creating two stacks to store alternate levels */
    stack<Node*> s1;
    stack<Node*> s2;
    
    s1.push(root);
    
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node* tmp = s1.top();
            s1.pop();
            res.push_back(tmp->data);
            
            /* Note that in stack2, right is pushed before left */
            if(tmp->right)
                s2.push(tmp->right);
            if(tmp->left)
                s2.push(tmp->left);
        }
        
        while(!s2.empty()){
            Node* tmp = s2.top();
            s2.pop();
            res.push_back(tmp->data);
            
            // Note that in stack1, left is pushed before right
            if(tmp->left)
                s1.push(tmp->left);
            if(tmp->right)
                s1.push(tmp->right);
        }
    }
    return res;
}