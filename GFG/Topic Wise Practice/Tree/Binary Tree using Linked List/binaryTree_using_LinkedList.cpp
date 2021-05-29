
/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

//Function to make binary tree from linked list.
/*Algorithm:
    1. Create an empty queue.
    2. Make the first node of the list as root, and enqueue it to the queue.
    3. Until we reach the end of the list, do the following.
        Dequeue one node from the queue. This is the current parent.
        Traverse two nodes in the list, add them as children of the current parent.
        Enqueue the two nodes into the queue.
*/

void convert(Node* head, TreeNode*& root) {
    // Your code here
    queue<TreeNode*> nodeQ;
    if (head == NULL)
        root = NULL;
        
    root = new TreeNode(head->data);
    nodeQ.push(root);
    head = head->next;
    
    while (head){
        TreeNode* curr = nodeQ.front();
        nodeQ.pop();
        curr->left = new TreeNode(head->data);
        nodeQ.push(curr->left);
        head = head->next;
        
        if (head == NULL)
            return;
        
        curr->right = new TreeNode(head->data);
        nodeQ.push(curr->right);
        head = head->next;
    }
}